#
# cms5-test.goethe.de vhost definition common includes
# shared by 80/443 virtual host definitions
# e.g.
# overwrites
#   - ServerName
#   - DocumentRoot
#   - Directory setting


# Note: we are inside VirtualHost definition!

    ServerName cms-dev.goethe.de
    ServerAlias cms5-test.goethe.de
    ServerAlias cms-test.goethe.de
    ServerAlias localhost

    DocumentRoot /var/www.cms.goethe.de/html
	
    Include conf.d/vhost.d/cms5-test.goethe.de-rewrite.inc
    Include conf.d/vhost.d/cms5-test.goethe.de-alias.inc

    Alias /goethe "/var/www.cms.goethe.de/html/contens5"
    Alias /services "/var/www.cms.goethe.de/html/contens5/goethe/services/_www"
    Alias /resources "/var/www.cms.goethe.de/html/contens5/goethe/Resources/_www"

    <Directory /var/www.cms.goethe.de/html>
        AllowOverride none
        Require all granted
    </Directory>


    # websocket
    ProxyRequests Off
    ProxyPreserveHost On
    ProxyPass /websocket/ ws://localhost:8080/websocket/
    ProxyPassReverse /websocket/ ws://localhost:8080/websocket/
	
<LocationMatch "/.*">
Order Allow,Deny
Allow from all
#SetEnvif X-Forwarded-For "144\.91\.112\.22" DenyAccess
#Deny from env=DenyAccess
</LocationMatch>
