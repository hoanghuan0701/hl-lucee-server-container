#
# This file is managed by ansible, don't make changes here - they will be overwritten.
#

# Use separate log files for the SSL virtual host; note that LogLevel
# is not inherited from httpd.conf.
LogLevel warn

#   SSL Engine Switch:
#   Enable/Disable SSL for this virtual host.
SSLEngine on

#   SSL Protocol support:
# List the enable protocol levels with which clients will be able to
# connect.  Disable SSLv2 access by default:
SSLProtocol all -SSLv2 -SSLv3 -TLSv1 -TLSv1.1

#   SSL Cipher Suite:
#   List the ciphers that the client is permitted to negotiate.
#   See the mod_ssl documentation for a complete list.
#SSLCipherSuite ECDH+AESGCM:DH+AESGCM:ECDH+AES256:DH+AES256:ECDH+AES128:DH+AES:RSA+AESGCM:RSA+AES:!3DES:!aNULL:!MD5:!DSS
SSLCipherSuite HIGH:!3DES:!aNULL:!MD5:!SEED:!IDEA:!CAMELLIA
SSLHonorCipherOrder On
