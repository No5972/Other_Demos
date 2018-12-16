package io.github.no5972.springbootdemo.controllers;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;

import io.github.no5972.springbootdemo.dao.ManagerDao;
import io.github.no5972.springbootdemo.models.Manager;

@Controller
@RequestMapping("/springbootdemo")
public class DemoController {
	@Autowired
	private ManagerDao managerDao;
	
	@RequestMapping("/getAllManagers")
	public @ResponseBody List<Manager> getAllManagers() {
		return managerDao.getAllManagers();
	}
}
