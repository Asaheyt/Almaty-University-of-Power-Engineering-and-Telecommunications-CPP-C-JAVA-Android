package kz.aues.lab12a;

import com.fasterxml.jackson.annotation.JsonProperty;

public class CuntryClient {
    private String Information;

    public CuntryClient(@JsonProperty("information")String con) {
        Information=con;
    }
    /*public CuntryClient(String information) {
        Information = information;
    }*/

    public String getInformation() {
        return Information;
    }

    public void setInformation(String information) {
        Information = information;
    }
}
