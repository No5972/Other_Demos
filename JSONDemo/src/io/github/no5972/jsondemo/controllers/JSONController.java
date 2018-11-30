package io.github.no5972.jsondemo.controllers;

import java.util.ArrayList;
import java.util.List;

import org.springframework.stereotype.Controller;
import org.springframework.ui.ModelMap;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;

import io.github.no5972.jsondemo.models.AnObject;

@Controller
public class JSONController {
	@RequestMapping("/getJSON")
	public @ResponseBody List<AnObject> getJSON(ModelMap model) {
		List<AnObject> result = new ArrayList<AnObject>();
		
		AnObject obj1 = new AnObject();
		obj1.setId(0);
		obj1.setName("Object 1");
		obj1.setValue("wujiuqier");
		
		AnObject obj2 = new AnObject();
		obj2.setId(1);
		obj2.setName("Object 2");
		obj2.setValue("ersierwu");
		
		AnObject obj3 = new AnObject();
		obj3.setId(2);
		obj3.setName("Object 1");
		obj3.setValue("sanyiwuyi");
		
		result.add(obj1);
		result.add(obj2);
		result.add(obj3);
		
		model.addAttribute("result", result);
		return result;
	}
	
	@RequestMapping("/test") 
	public String test() {
		return "test";
	}
}
