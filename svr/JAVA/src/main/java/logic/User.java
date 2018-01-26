package logic;

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.lang.reflect.Type;
import java.util.Random;

import com.google.gson.Gson;
import com.google.gson.GsonBuilder;
import com.google.gson.JsonElement;
import com.google.gson.JsonObject;
import com.google.gson.JsonPrimitive;
import com.google.gson.JsonSerializationContext;
import com.google.gson.JsonSerializer;
import java.lang.reflect.Parameter;

public class User extends UserInformation implements Entity {

    final private Gson gson = new GsonBuilder().disableHtmlEscaping()
            .registerTypeAdapter(Class.class, new JsonSerializer<Class<?>>() {
                @Override
                public JsonElement serialize(Class<?> src, Type typeOfSrc, JsonSerializationContext context) {
                    return new JsonPrimitive(src.getName());
                }
            }).create();

    protected String decry(String msg) {
        return msg;
    }

    protected String encry(String msg) {
        return msg;
    }

    protected User construct(String id) {
        if (null == id) {
            id = new Random().toString();
        }
        setId(id);
        setName("test");
        return this;
    }

    private boolean marchParameter(Parameter p, JsonElement je) {
        if (null == je || je.isJsonNull()) {
            return false;
        }
        Class<?> type = p.getType();
        if (je.isJsonArray() && type.isArray()) {
            return true;
        }
        if (je.isJsonPrimitive() && type.isPrimitive()) {
            return true;
        }
        return (!type.isPrimitive() && !type.isEnum());
    }

    private String getName(Parameter parametor) {
        String name = parametor.getName();
        JsonMapping jm = parametor.getAnnotation(JsonMapping.class);
        if (null != jm) {
            name = jm.name();
        }
        return name;
    }

    private boolean marchMethod(Method method, JsonObject request) {

        try {
            Parameter[] parameters = method.getParameters();

            if (null == request || request.isJsonNull()) {
                return (parameters.length == 0);
            }
            if (parameters.length > request.size()) {
                return false;
            }

            for (Parameter parametor : parameters) {
                String name = getName(parametor);
                System.out.println("will be check : " + name);
                JsonElement je = request.get(name);
                if (!marchParameter(parametor, je)) {
                    return false;
                }
            }
            return true;
        } catch (IllegalArgumentException e) {
            e.printStackTrace();
        }
        return false;
    }

    private Object invokeMethod(Method method, JsonObject request) throws InvocationTargetException, IllegalAccessException {
        if (request.isJsonNull()) {
            return method.invoke(this, (Object) null);
        }
        Parameter[] parameters = method.getParameters();
        if (1 == parameters.length) {
            Object arg = gson.fromJson(request, parameters[0].getType());
            return method.invoke(this, arg);
        }
        JsonObject json = gson.fromJson(request, JsonObject.class);
        Object[] args = new Object[method.getParameterCount()];
        for (int i = 0; i < args.length; ++i) {
            JsonElement je = json.get(getName(parameters[i]));
            args[i] = gson.fromJson(je, parameters[i].getType());
        }
        return method.invoke(this, args);
    }

    /**
     *
     * @param cls
     * @param action
     * @param request
     * @return
     */
    private Method lookupMethod(Class<?> cls, String action, JsonObject request) {
        if (null == cls || null == action || action.isEmpty()) {
            return null;
        }
        Method[] methods = cls.getDeclaredMethods();
        for (Method method : methods) {
            if (method.getName().equals(action) && marchMethod(method, request)) {
                return method;
            }
        }
        if (cls.getName().equalsIgnoreCase("Object")) {
            return null;
        }
        return lookupMethod(cls.getSuperclass(), action, request);
    }

    protected String invoker(String action, JsonObject request) throws IllegalAccessException, IllegalArgumentException,
            InvocationTargetException, NoSuchMethodException, SecurityException {

        Method method = lookupMethod(getClass(), action, request);
        if (null != method) {
            Object resp = invokeMethod(method, request);
            return gson.toJson(resp);
        } else {
            throw new NoSuchMethodException(action);
        }
    }

    public User(String id) {
        construct(id);
    }

    public User() {

    }

    /**
     *
     * @param id
     * @return
     */
    @Override
    public User instance(String id) {
        try {
            User inst;
            inst = (User) this.getClass().newInstance();
            return inst.construct(id);
        } catch (InstantiationException | IllegalAccessException e) {
        }
        return this;
    }

    /**
     *
     * @param action
     * @param content
     * @return
     */
    @Override
    public String excute(String action, String content) {

        try {
            String request = this.decry(content);
            JsonObject jo = gson.fromJson(request, JsonObject.class);
            String response = this.invoker(action, jo);
            return this.encry(response);
        } catch (IllegalAccessException
                | InvocationTargetException
                | NoSuchMethodException
                | IllegalArgumentException
                | SecurityException e) {
            e.printStackTrace();
        }
        return "{status:\"00\"}";
    }

    public InitResponse Init(InitRequest req) {
        InitResponse rsp = new InitResponse();
        System.out.println("this is process by User " + req.getOsName());
        rsp.setVirtualId("aaaaaaa");
        return rsp;
    }

}
