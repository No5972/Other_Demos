package io.github.no5972.springmvc1;

import java.io.InputStream;
import java.util.List;

import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;
import org.springframework.stereotype.Controller;
import org.springframework.ui.ModelMap;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.RequestMapping;
@Controller
public class SearchNewsController {
	@RequestMapping("/searchnews.do")
	public String add(@ModelAttribute("SpringWeb")News news, 
			   ModelMap model) {
		String resource = "conf.xml";
		InputStream is = SearchNewsController.class.getClassLoader().getResourceAsStream(resource);
		SqlSessionFactory sessionFactory = new SqlSessionFactoryBuilder().build(is);
		SqlSession session = sessionFactory.openSession();
		String statement = "io.github.no5972.springmvc1.NewsMapping.getNewsByTitle";
		System.out.println(news.getTitle());
		List<News> listNews = session.selectList(statement, news.getTitle());
		model.addAttribute("list", listNews);
//		for(News inews : listNews){
//			System.out.println(inews.getTitle());
//		}
		System.out.println(listNews.size());
		return "search_result";
	}
}
