package io.github.no5972;

public class MyServiceImpl implements MyService {

	@Override
	public int validLogin(String username, String pass) {
		// TODO Auto-generated method stub
		if (username.equals("admin")&&pass.equals("admin")) 
			return 99; 
		else return -1;
	}

}
