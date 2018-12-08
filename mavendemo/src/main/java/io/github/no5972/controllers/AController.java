package io.github.no5972.controllers;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;

import io.github.no5972.models.TargetObject;

@Controller
public class AController {
	@RequestMapping("/getresult.php")
	public @ResponseBody TargetObject getResult() {
		TargetObject result = new TargetObject();
		result.setId(6);
		result.setValue("wujiuqier");
		return result;
	}
}
