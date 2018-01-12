import javax.servlet.*;
import javax.servlet.http.*;
import java.io.*;

public class Demo21 extends HttpServlet {

	private String message;

	public void init() throws ServletException {

	}

	public void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

		response.setContentType("text/html");
		response.setCharacterEncoding("UTF-8");
		request.setCharacterEncoding("GBK");
		PrintWriter out = response.getWriter();
		//String output = "服务器返回的数据是：" + new String(new String(request.getParameter("add1").getBytes("UTF-8"), "ISO-8859-1").getBytes("ISO-8859-1"),"UTF-8") + "喜欢" + request.getParameter("add2");
		//out.println(new String(output.getBytes("GBK"), "UTF-8"));
		//out.println(output);
		System.out.println(request.getParameter("add1"));
		out.print(new String("服务器返回的数据是：".getBytes("GBK"), "UTF-8"));
		out.print(java.net.URLDecoder.decode(request.getParameter("add1"),"UTF-8"));
		out.print(new String("喜欢".getBytes("GBK"), "UTF-8"));
		out.println(java.net.URLDecoder.decode(request.getParameter("add2"),"UTF-8"));
	}

	public void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doGet(request, response);

	}

	public void destroy() {

	}
}