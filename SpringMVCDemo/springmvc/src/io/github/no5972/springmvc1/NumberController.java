package io.github.no5972.springmvc1;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.servlet.ModelAndView;
import org.springframework.ui.ModelMap;
@Controller
public class NumberController {
   @RequestMapping(value = "/student", method = RequestMethod.GET)
   public ModelAndView student() {
      return new ModelAndView("student", "command", new Numbers());
   }   
   @RequestMapping(value = "/addStudent", method = RequestMethod.POST)
   public String addStudent(@ModelAttribute("SpringWeb")Numbers numbers, 
   ModelMap model) {
	   System.out.println("handling inputs");
      model.addAttribute("add1", numbers.getAdd1());
      model.addAttribute("add2", numbers.getAdd2());
      int sum = numbers.getAdd1() + numbers.getAdd2();
      model.addAttribute("result", sum);
      return "result";
   }
}