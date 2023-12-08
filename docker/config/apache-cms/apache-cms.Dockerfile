FROM httpd:2.4

#WORKDIR /usr/local/apache2/modules/
#COPY ./modules/mod_cfml.so mod_cfml.so
#COPY mod_cfml.so mod_cfml.so

#RUN httpd -k restart

WORKDIR /usr/local/apache2/conf/
COPY cms-httpd.conf httpd.conf

WORKDIR /usr/local/apache2/conf/extra
COPY http-proxy-html.conf http-proxy-html.conf

WORKDIR /usr/local/apache2/conf.d/
COPY conf.d/vhost.d/ vhost.d
#COPY certs certs

EXPOSE 80 443 8080

CMD ["apachectl", "-k", "start", "-DFOREGROUND"]
