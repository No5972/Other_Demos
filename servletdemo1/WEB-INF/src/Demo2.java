// �������� java ��
import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;

// ��չ HttpServlet ��
public class Demo2 extends HttpServlet {
 
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
      int a=Integer.parseInt(request.getParameter("add1")), b=Integer.parseInt(request.getParameter("add2"));
      out.println(a+b);
      

  }

  public void doPost(HttpServletRequest request,
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
  
  public void destroy()
  {
      // ʲôҲ����
  }
}
