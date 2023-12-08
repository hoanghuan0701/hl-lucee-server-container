RewriteEngine On
#writeLog "/var/tmp/rewrite.log"
#RewriteLogLevel 5

RewriteCond %{HTTP_HOST} ^cms5-test.goethe.de
RewriteRule (.*) https://cms-test.goethe.de$1 [R=301,L]

RewriteRule ^/hilfe/(.+)\.html /hilfe/index.cfm?page=$1.html [PT,L]

### CAS Client ###
RewriteRule ^/?services/cas/(service|signup|login|logout|status)/([^/]*)/$ /services/cas/$1/?app=$2 [QSA,PT,L]
RewriteRule ^/?services/cas/action/([^/]*)/([^/]*)$ /services/cas/action/index.cfm?app=$1&action=$2 [QSA,PT,L]

## Imageconverter ##
RewriteRule ^/?resources/files/(.+)-w([0-9]{1,4})-h([0-9]{1,4})\.(gif|jpg|png) /services/imageconverter/image.cfm?source=SIMAGEURL$1.$4&resize=width:$2_height:$3 [PT,L]
RewriteRule ^/?resources/files/(.+)-formatkey-([a-zA-Z_0-9\-]+)\.(gif|jpg|png|tiff|jpeg|) /services/imageconverter/image.cfm?source=SIMAGEURL$1.$3&format_key=$2 [PT,L]
  
## REWRITE ALL CAPITAL ##
RewriteRule ^/?(INS|Ins)/(.+)$ /ins/$2 [R=301,L]

RewriteRule ^/?(prj|ins)/([a-zA-Z_]+)/files/([a-zA-Z_0-9]+)/([a-zA-Z_0-9-.]+)\.([a-z]{3}) /resources/files/$3/$4.$5 [R=301,L]

## REWRITE SITEMAP to html ##
RewriteRule ^/sitemap.xml  /de/metasitemap.cfm [T=application/xml,PT]
RewriteRule ^/?(.+)/sitemap.xml  /$1/sitemap.cfm [T=application/xml,PT]


#rewrite for brieffreunde
RewriteRule ^/?(ins/de/prj)/([a-zA-Z_]+)/(.+)/([a-zA-Z_]+)index\.htm.{0,1}$ /$1/$2/$4/$3.html [R=301,L]
RewriteRule ^/?(ins/de/prj)/([a-zA-Z_]+)/([a-zA-Z_]+)index\.htm.{0,1}$ /$1/$2/$3/index.html [R=301,L]
RewriteRule ^/?(ins/de/prj)/([a-zA-Z_]+)/(.+)/([a-z]{2,4})([0-9]+)\.htm.{0,1}$ /$1/$2/$4/$3/$5.html [R=301,L]

#rewrite for wissen projekte
RewriteRule ^/?(wis/prj)/([a-zA-Z_]+)/(.+)/([a-zA-Z_]+)index\.htm.{0,1}$ /$1/$2/$4/$3.html [R=301,L]
RewriteRule ^/?(wis/prj)/([a-zA-Z_]+)/([a-zA-Z_]+)index\.htm.{0,1}$ /$1/$2/$3/index.html [R=301,L]
RewriteRule ^/?(wis/prj)/([a-zA-Z_]+)/(.+)/([a-z]{2,4})([0-9]+)\.htm.{0,1}$ /$1/$2/$4/$3/$5.html [R=301,L]

RewriteRule ^/?(prj|ins)/([a-zA-Z_]+)/files/([a-zA-Z_0-9]+)/([a-zA-Z_0-9-.]+)\.([a-z]{3}) /resources/files/$3/$4.$5 [R=301,L]


#rewrite for prj
RewriteRule ^/?(ins/[a-zA-Z_]+/prj)/([a-zA-Z_]+)/(.+)/([a-zA-Z_]+)index\.htm.{0,1}$ /$1/$2/$4/$3.html [R=301,L]
RewriteRule ^/?(ins/[a-zA-Z_]+/prj)/([a-zA-Z_]+)/([a-zA-Z_]+)index\.htm.{0,1}$ /$1/$2/$3/index.html [R=301,L]
RewriteRule ^/?(ins/[a-zA-Z_]+/prj)/([a-zA-Z_]+)/(.+)/([a-z]{2,4})([0-9]+)\.htm.{0,1}$ /$1/$2/$4/$3/$5.html [R=301,L]

#rewrite for subfolder index pages
RewriteRule ^/?(prj|ins)/([a-zA-Z_]+)/(.+)/([a-zA-Z_]+)index\.htm$ /$1/$2/$4/$3.html [R=301,L]
#rewrite for index page
RewriteRule ^/?(prj|ins)/([a-zA-Z_]+)/([a-zA-Z_]+)index\.htm$ /$1/$2/$3/index.html [R=301,L]

#rewrite for article pages
RewriteRule ^/?(prj|ins)/([a-zA-Z_]+)/(.+)/([a-z]{2,4})(\d{5,10})\.htm$ /$1/$2/$4/$3/$5.html [R=301,L]

#rewrite for events archive pages
RewriteRule ^/?(prj|ins)/([a-zA-Z_]+)/(.+)/acv/(.+)/([a-z]{2,4})(\d{5,10})v\.htm$ /$1/$2/$5/$3/acv.cfm?fuseaction=events.detail&event_id=$6 [R=301,L]

#rewrite for events application pages
RewriteRule ^/?(prj|ins)/([a-zA-Z_]+)/ver/([a-z]{2,4})(\d{5,10})v\.htm.{0,1}$ /$1/$2/$4/$3.cfm?fuseaction=events.detail&event_id=$5 [R=301,L]
RewriteRule ^/?(prj|ins)/([a-zA-Z_]+)/(.+)/ver/([a-z]{2,4})(\d{5,10})v\.htm.{0,1}$ /$1/$2/$4/$3/ver.cfm?fuseaction=events.detail&event_id=$5 [R=301,L]

#rewrite for events pages
RewriteRule ^/?(prj|ins)/([a-zA-Z_]+)/(.+)/([a-z]{2,4})(\d{5,10})v\.htm /$1/$2/$4/$3/$5.html [R=301,L]

#rewrite for paths only
#RewriteRule ^/?(prj|ins|ins/de/prj/)/(.+)/$ /$1/$2.html [L]
#RewriteRule ^/?(prj|ins|ins/de/prj/)/([a-zA-Z_]+)/(de|en)/$ /$1/$2/$3/index.html [L]