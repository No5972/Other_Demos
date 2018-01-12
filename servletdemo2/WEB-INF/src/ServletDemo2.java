import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import org.json.JSONObject;
import org.json.JSONException;

public class ServletDemo2 extends HttpServlet {
 
  private String message;

  public void init() throws ServletException
  {
      
  }

  public void doGet(HttpServletRequest request,
                    HttpServletResponse response)
            throws ServletException, IOException 
  {
      
      response.setContentType("text/html");
      
      PrintWriter out = response.getWriter();
      try {
          int a=Integer.parseInt(request.getParameter("add1")), b=Integer.parseInt(request.getParameter("add2"));
          JSONObject json=new JSONObject();
          json.put("result1",a*2);
          json.put("result2",b*2);
          json.put("result3",a+b);
          out.println(json.toString());
      } catch (NumberFormatException e) {
          out.println("Number Format Error!");
      } catch (JSONException e) {
          out.println("{ \"result1\": \"Internal Error!\"}");
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
      
  }
}
