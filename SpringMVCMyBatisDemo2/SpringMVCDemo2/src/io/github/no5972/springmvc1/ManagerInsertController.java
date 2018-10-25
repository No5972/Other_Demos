package io.github.no5972.springmvc1;

import java.io.InputStream;
import java.util.List;

import javax.servlet.http.HttpSession;

import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;
import org.springframework.stereotype.Controller;
import org.springframework.ui.ModelMap;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.RequestMapping;
@Controller

public class ManagerInsertController {
	@RequestMapping("/insertManager.do")
	public String add(@ModelAttribute("SpringWeb")Manager manager, 
			   ModelMap model) {
		String resource = "conf.xml";
		InputStream is = SearchNewsController.class.getClassLoader().getResourceAsStream(resource);
		SqlSessionFactory sessionFactory = new SqlSessionFactoryBuilder().build(is);
		SqlSession session = sessionFactory.openSession();
		manager.setNumber(0);
		session.insert("addManager", manager);
		session.commit();
		List<Manager> listManager = session.selectList("printManager");
		model.addAttribute("list", listManager);
		System.out.println(listManager.size());
		return "addUser";
	}
	@RequestMapping("/removeManager.do")
	public String remove(int id, ModelMap model) {
		String resource = "conf.xml";
		InputStream is = SearchNewsController.class.getClassLoader().getResourceAsStream(resource);
		SqlSessionFactory sessionFactory = new SqlSessionFactoryBuilder().build(is);
		SqlSession session = sessionFactory.openSession();
		session.delete("removeManager", id);
		session.commit();
		List<Manager> listManager = session.selectList("printManager");
		model.addAttribute("list", listManager);
		System.out.println(listManager.size());
		return "addUser";
	}
	@RequestMapping("/getUser.do")
	public String print(ModelMap model) {
		String resource = "conf.xml";
		InputStream is = SearchNewsController.class.getClassLoader().getResourceAsStream(resource);
		SqlSessionFactory sessionFactory = new SqlSessionFactoryBuilder().build(is);
		SqlSession session = sessionFactory.openSession();
		List<Manager> listManager = session.selectList("printManager");
		model.addAttribute("list", listManager);
		System.out.println(listManager.size());
		return "addUser";
	}
	@RequestMapping("/updatingManager.do")
	public String updating(int id, ModelMap model, HttpSession httpSession) {
		String resource = "conf.xml";
		InputStream is = SearchNewsController.class.getClassLoader().getResourceAsStream(resource);
		SqlSessionFactory sessionFactory = new SqlSessionFactoryBuilder().build(is);
		SqlSession session = sessionFactory.openSession();
		Manager manager = session.selectOne("editOneManager", id);
		model.addAttribute("id", manager.getId());
		model.addAttribute("account", manager.getAccount());
		model.addAttribute("name", manager.getName());
		model.addAttribute("password", manager.getPassword());
		// 敲黑板！如何防止不该修改的表单参数被篡改
		httpSession.setAttribute("id", id);
		return "editManager";
	}
	@RequestMapping("/updateManager.do")
	public String update(Manager manager, ModelMap model, HttpSession httpSession) {
		String resource = "conf.xml";
		InputStream is = SearchNewsController.class.getClassLoader().getResourceAsStream(resource);
		SqlSessionFactory sessionFactory = new SqlSessionFactoryBuilder().build(is);
		SqlSession session = sessionFactory.openSession();
		// 敲黑板！如何防止不该修改的表单参数被篡改
		manager.setId((int) httpSession.getAttribute("id"));
		session.update("updateManager", manager);
		session.commit();
		List<Manager> listManager = session.selectList("printManager");
		model.addAttribute("list", listManager);
		System.out.println(listManager.size());
		return "addUser";
	}
}