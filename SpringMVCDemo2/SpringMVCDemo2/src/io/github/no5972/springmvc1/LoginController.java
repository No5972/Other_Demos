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

public class LoginController {
	@RequestMapping("/login.do")
	public String add(@ModelAttribute("SpringWeb")Users user, 
			   ModelMap model) {
		if (user.getUsername().equals("wujiuqier")&&user.getPassword().equals("wo"))
			return "success"; else return "fail";
	}
}