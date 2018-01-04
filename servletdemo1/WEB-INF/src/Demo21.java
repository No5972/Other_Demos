// �������� java ��
import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
//import net.sf.json.JSON;
//import net.sf.json.JSONObject;

// ��չ HttpServlet ��
public class Demo21 extends HttpServlet {
 
  private String message;

  public void init() throws ServletException
  {
      // ִ�б���ĳ�ʼ��
      //message = "Hello World at "+new java.util.Date().toString();
  }

  public void doGet(HttpServletRequest request,
                    HttpServletResponse response)
            throws ServletException, IOException
  {
      // ������Ӧ��������
      response.setContentType("text/html");
      // ʵ�ʵ��߼���������
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
      // ʲôҲ����
  }
}
