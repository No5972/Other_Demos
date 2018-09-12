package io.github.no5972;

import com.opensymphony.xwork2.ActionSupport;

public class LoginAction extends ActionSupport {
	private String username;
	private String password;
	private MyService ms;
	public String getUsername() {
		return username;
	}
	public void setUsername(String username) {
		this.username = username;
	}
	public String getPassword() {
		return password;
	}
	public void setPassword(String password) {
		this.password = password;
	}
	public void setMs(MyService ms) {
		this.ms = ms;
	}
	public String execute() throws Exception {
		if (ms.validLogin(getUsername(), getPassword())>0) {
			addActionMessage("SPRING CONFIGURATION SUCCESS");
			return SUCCESS;
		}
		return ERROR;
	}
}
