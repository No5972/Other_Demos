package io.github.no5972.springbootdemo.models;

public class Manager {

	private int id;
	private String account;
	private String name;
	private String password;
	private int number;
	private Manager() {}
	
	private static class ManagerInstance {
		private final static Manager instance = new Manager();
	}
	
	public static Manager getInstance() {
		return ManagerInstance.instance;
	}
	
	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
	}

	public String getAccount() {
		return account;
	}

	public void setAccount(String account) {
		this.account = account;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getPassword() {
		return password;
	}

	public void setPassword(String password) {
		this.password = password;
	}

	public int getNumber() {
		return number;
	}

	public void setNumber(int number) {
		this.number = number;
	}
}
