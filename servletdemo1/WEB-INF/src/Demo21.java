// 导入必需的 java 库
import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
//import net.sf.json.JSON;
//import net.sf.json.JSONObject;

// 扩展 HttpServlet 类
public class Demo21 extends HttpServlet {
 
  private String message;

  public void init() throws ServletException
  {
      // 执行必需的初始化
      //message = "Hello World at "+new java.util.Date().toString();
  }

  public void doGet(HttpServletRequest request,
                    HttpServletResponse response)
            throws ServletException, IOException
  {
      // 设置响应内容类型
      response.setContentType("text/html");
      // 实际的逻辑是在这里
      PrintWriter out = response.getWriter();
      try {
          int a=Integer.parseInt(request.getParameter("add1")), b=Integer.parseInt(request.getParameter("add2"));
          out.println(a+b);
      } catch (NumberFormatException e) {
          out.println("Number Format Error!");
      }
  }

  public void doPost(HttpServletRequest request,
                    HttpServletResponse response)
            throws ServletException, IOException
  {
      doGet(request, response);
      

  }
  
  public void destroy()
  {
      // 什么也不做
  }
}
