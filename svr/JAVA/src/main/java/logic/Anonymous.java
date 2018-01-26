package logic;

public class Anonymous extends User {

    public Anonymous() {
        super();
    }

    @Override
    public InitResponse Init(InitRequest req) {
        if (null == req) {
            return null;
        }
        InitResponse rsp = super.Init(req);
        System.out.println("this processed by Anonymous " + req.getOsName());
        rsp.setVirtualId("bbbb");
        return rsp;
    }

    /**
     *
     * @param osName
     * @param time
     * @return
     */
    public InitResponse Init(
            @JsonMapping(name = "osName") String osName,
            @JsonMapping(name = "time") String time) {
        InitResponse rsp = new InitResponse();
        System.out.println(osName + " : " + time);
        rsp.setVirtualId(time);
        return rsp;
    }
}
