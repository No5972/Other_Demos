# NOTE: Available only on tomcat 7, Spring 3.2.0, JDK 1.7
Passed the test under Windows 10 1511

Spring Distribution: http://101.110.118.47/maven.springframework.org/release/org/springframework/spring/3.2.0.RELEASE/spring-framework-3.2.0.RELEASE-dist.zip

some notes:
1. Import Spring JARs to <b>WebContent/WEB-INF/lib</b> directory!
2. Edit <a href="https://github.com/No5972/Other_Demos/blob/master/SpringMVCDemo2/SpringMVCDemo2/WebContent/WEB-INF/web.xml">web.xml</a> 
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
3. Edit <a href="https://github.com/No5972/Other_Demos/blob/master/SpringMVCDemo2/SpringMVCDemo2/WebContent/WEB-INF/HelloWeb-servlet.xml">Spring MVC XML</a>
```
   <bean class="org.springframework.web.servlet.mvc.annotation.AnnotationMethodHandlerAdapter" />
   <context:component-scan base-package="io.github.no5972.springmvc1" />

   <bean class="org.springframework.web.servlet.view.InternalResourceViewResolver">
      <property name="prefix" value="/" />
      <property name="suffix" value=".jsp" />
   </bean>
```

4. Edit Java Codes! (Use annotation method)
