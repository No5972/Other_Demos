package io.github.no5972.springmvc1;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.servlet.ModelAndView;
import org.springframework.web.servlet.mvc.AbstractCommandController;
import org.springframework.ui.ModelMap;
import org.springframework.validation.BindException;
@Controller

public class NumberController {
	@RequestMapping("/add.do")
	   public String add(@ModelAttribute("SpringWeb")Numbers numbers, 
			   ModelMap model) {
		   System.out.println("handling inputs");
		      model.addAttribute("add1", numbers.getAdd1());
		      model.addAttribute("add2", numbers.getAdd2());
		      int sum = numbers.getAdd1() + numbers.getAdd2();
		      model.addAttribute("result", sum);
		      return "result";
	}	
	@RequestMapping("/times.do")
	   public String times(@ModelAttribute("SpringWeb")Numbers numbers, 
			   ModelMap model) {
		   System.out.println("handling inputs");
		      model.addAttribute("add1", numbers.getAdd1());
		      model.addAttribute("add2", numbers.getAdd2());
		      int sum = numbers.getAdd1() * numbers.getAdd2();
		      model.addAttribute("result", sum);
		      return "result";
	}
}