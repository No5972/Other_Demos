# NOTE: Available only on tomcat 7 or higher, Spring 5.1.0 or higher, JDK 1.7 or higher
Passed the test under CentOS 6.5
Spring Distribution: http://101.110.118.47/maven.springframework.org/release/org/springframework/spring/5.1.0.RELEASE/spring-framework-5.1.0.RELEASE-dist.zip

some notes:
1. Edit <a href="https://github.com/No5972/Other_Demos/blob/master/SpringMVCDemo/springmvc/WebContent/WEB-INF/web.xml">web.xml</a> 
```
<servlet>
        <servlet-name>HelloWeb</servlet-name>
        <servlet-class>
           org.springframework.web.servlet.DispatcherServlet
        </servlet-class>
        <load-on-startup>1</load-on-startup>
    </servlet>

    <servlet-mapping>
        <servlet-name>HelloWeb</servlet-name>
        <url-pattern>/</url-pattern>
    </servlet-mapping>

<listener>  
  <listener-class>org.springframework.web.context.ContextLoaderListener</listener-class>  
</listener>  
<context-param>  
  <param-name>contextConfigLocation</param-name>  
  <param-value>/WEB-INF/HelloWeb-servlet.xml</param-value>  
</context-param>
```
2. Edit <a href="https://github.com/No5972/Other_Demos/blob/master/SpringMVCDemo/springmvc/WebContent/WEB-INF/HelloWeb-servlet.xml">Spring MVC XML</a>
```
   <bean class="org.springframework.web.servlet.mvc.annotation.AnnotationMethodHandlerAdapter" />
   <context:component-scan base-package="io.github.no5972.springmvc1" />

   <bean class="org.springframework.web.servlet.view.InternalResourceViewResolver">
      <property name="prefix" value="/" />
      <property name="suffix" value=".jsp" />
   </bean>
```

3. Edit Java Codes! (Use annotation method)
