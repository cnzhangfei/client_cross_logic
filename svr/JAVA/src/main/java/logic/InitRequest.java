package logic;

public class InitRequest {

    private String clientVersion;

    private String osName;

    private String osVersion;

    private String deviceModel;

    private String deviceResolution;

    private String deviceId;
    private String apkChannel;
    private String virtualId;

    /**
     * @return the clientVersion
     */
    public String getClientVersion() {
        return clientVersion;
    }

    /**
     * @param clientVersion the clientVersion to set
     */
    public void setClientVersion(String clientVersion) {
        this.clientVersion = clientVersion;
    }

    /**
     * @return the osName
     */
    public String getOsName() {
        return osName;
    }

    /**
     * @param osName the osName to set
     */
    public void setOsName(String osName) {
        this.osName = osName;
    }

    /**
     * @return the osVersion
     */
    public String getOsVersion() {
        return osVersion;
    }

    /**
     * @param osVersion the osVersion to set
     */
    public void setOsVersion(String osVersion) {
        this.osVersion = osVersion;
    }

    /**
     * @return the deviceModel
     */
    public String getDeviceModel() {
        return deviceModel;
    }

    /**
     * @param deviceModel the deviceModel to set
     */
    public void setDeviceModel(String deviceModel) {
        this.deviceModel = deviceModel;
    }

    /**
     * @return the deviceResolution
     */
    public String getDeviceResolution() {
        return deviceResolution;
    }

    /**
     * @param deviceResolution the deviceResolution to set
     */
    public void setDeviceResolution(String deviceResolution) {
        this.deviceResolution = deviceResolution;
    }

    /**
     * @return the deviceId
     */
    public String getDeviceId() {
        return deviceId;
    }

    /**
     * @param deviceId the deviceId to set
     */
    public void setDeviceId(String deviceId) {
        this.deviceId = deviceId;
    }

    /**
     * @return the apkChannel
     */
    public String getApkChannel() {
        return apkChannel;
    }

    /**
     * @param apkChannel the apkChannel to set
     */
    public void setApkChannel(String apkChannel) {
        this.apkChannel = apkChannel;
    }

    /**
     * @return the virtualId
     */
    public String getVirtualId() {
        return virtualId;
    }

    /**
     * @param virtualId the virtualId to set
     */
    public void setVirtualId(String virtualId) {
        this.virtualId = virtualId;
    }

}
