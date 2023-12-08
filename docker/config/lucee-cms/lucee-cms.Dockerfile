FROM lucee/lucee:5.4.0.80-tomcat9.0-jdk11-openjdk

ENV LUCEE_JAVA_OPTS "-Xms512m -Xmx4096m"

ARG LUCEE_ADMIN_PASSWORD=

RUN if [ "$LUCEE_ADMIN_PASSWORD" != "" ] ; then \
        echo $LUCEE_ADMIN_PASSWORD > "/opt/lucee/server/lucee-server/context/password.txt" ; \
    fi

#WORKDIR /opt/lucee/server/lucee-server/context
#COPY lucee-server.xml lucee-server.xml

WORKDIR /opt/lucee/web/
COPY lucee-web.xml.cfm .

WORKDIR /usr/local/tomcat/conf/
COPY server.xml .

WORKDIR /usr/local/tomcat/lib/
#COPY ./lib/gson-2.10.1.jar .
#COPY ./lib/slf4j-api-2.0.9.jar .
#COPY ./lib/commons-pool2-2.12.0.jar .
#COPY ./lib/jedis-4.3.0.jar .

WORKDIR /opt/lucee/server/lucee-server/context/lib/
COPY ./lib .

#WORKDIR /usr/local/tomcat/conf/
#WORKDIR /opt/lucee/server/lucee-server/bundles
#COPY ./lib .
