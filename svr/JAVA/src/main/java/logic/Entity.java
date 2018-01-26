package logic;

public interface Entity {

    Entity instance(String id);

    String excute(String action, String parameter);

}
