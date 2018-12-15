package io.github.no5972.springbootdemo.controllers;

import org.springframework.stereotype.Controller;
import org.springframework.ui.ModelMap;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;

import io.github.no5972.springbootdemo.models.OperationResult;

@Controller
@RequestMapping("/springbootdemo")
public class DemoController {
	@RequestMapping("/getResult")
	public @ResponseBody OperationResult getResult() {
		OperationResult result = new OperationResult();
		result.setCode(0);
		result.setMessage("test");
		return result;
	}
	
	@RequestMapping("/getAnotherResult")
	public String getAnotherResult(ModelMap model) {
		model.addAttribute("result", "test");
		return "result";
	}
	
	@RequestMapping("/login1")
	public @ResponseBody OperationResult getLogin(String username, String password) {
		OperationResult result = new OperationResult();
		if (username.equals("wujiuqier") && password.equals("password")) {
			result.setCode(0);
			result.setMessage("success");
		} else {
			result.setCode(-1);
			result.setMessage("username or password is incorrect");
		}
		return result;
	}
}
