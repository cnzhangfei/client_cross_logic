/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.marshal.java.servlet;

import com.google.gson.Gson;
import com.google.gson.GsonBuilder;
import com.google.gson.JsonElement;
import com.google.gson.JsonObject;
import com.google.gson.JsonPrimitive;
import com.google.gson.JsonSerializationContext;
import com.google.gson.JsonSerializer;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.Reader;
import java.lang.reflect.Type;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.servlet.ServletContext;
import javax.servlet.ServletContextEvent;
import javax.servlet.ServletContextListener;


/**
 * Web application lifecycle listener.
 *
 * @author ShiHua
 */
public class JsonListener implements ServletContextListener {

    private Gson gson = new GsonBuilder().disableHtmlEscaping()
            .registerTypeAdapter(Class.class, new JsonSerializer<Class<?>>() {
                @Override
                public JsonElement serialize(Class<?> src, Type typeOfSrc, JsonSerializationContext context) {
                    return new JsonPrimitive(src.getName());
                }
            }).create();

    @Override
    public void contextInitialized(ServletContextEvent sce) {
        try {
            ServletContext context = sce.getServletContext();
            String configFile = context.getInitParameter("contextConfigure");
            String path = context.getRealPath(configFile);
            Reader reader = new FileReader(new File(path));
            JsonObject jo = gson.fromJson(reader, JsonObject.class);
            context.setAttribute("json", jo);
            System.out.println("here create instance from json describe" + jo.toString());
        } catch (FileNotFoundException ex) {
            Logger.getLogger(JsonListener.class.getName()).log(Level.SEVERE, null, ex);
        }

    }

    @Override
    public void contextDestroyed(ServletContextEvent sce) {
    }
}
