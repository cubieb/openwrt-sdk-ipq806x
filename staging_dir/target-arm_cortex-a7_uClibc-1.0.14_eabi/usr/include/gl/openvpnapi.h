#ifndef _OPENVPNAPI_H
#define _OPENVPNAPI_H

#include <gl/gjson.h>

/**
 * start_vpn_server: 启动openvpn server服务
 * 
 * @return: 0=succeed, -1=openvpn missing, -2=certificate file missing, -3=ovpn config missing, -4=startup script missing -5=openvpn server uci config missing -6=server already run -7=fail to start server
 */
int start_vpn_server(json_object *input, json_object *output);

/**  
 * stop_vpn_server: 停止openvpn server服务
 * 
 * @return: 0=succeed
 */
int stop_vpn_server(json_object *input, json_object *output);  

/** 
 * get_vpn_server_status: 获取vpn server状态
 * 
 * #log {string|m}
 * #clients {json_object|m}
 * clients json_object type as follow:
 * {
 *    "ip": {string | m},
 *    "sent": {unsigned long long | m},
 *    "recv": {unsigned long long | m}
 * }
 */
int get_vpn_server_status(json_object *input, json_object *output);  

/**
 * get_ovpn_config: 获取vpn server配置信息
 * 
 * #auth {string|m}
 * #proto {string|m}
 * #port {string|m}
 * #dev {string|m}
 * #cipher {string|m}
 * #comp {string|m}
 * #subnet {string|m}
 * #mask {string|m}
 * #host {string|m}
 * @return: 0=succeed, -1=uci config missing -2=parameter missing
 */
int get_vpn_config(json_object *input, json_object *output);  

/**
 * create_ovpn_config: 生成vpn server ovpn文件以及vpn client ovpn文件
 *
 * @auth {string}: default is "SHA1"
 * @proto {string}: TCP or UDP, default is UDP
 * @port {string}: default is "1194"
 * @dev {string}: tun or tap, only support tun now
 * @cipher {string}: cryptographic cipher, default is "BF-CBC"
 * @comp {string}: compression, default is "adaptive" 
 * @subnet {string}: private subnet with the tunnel, default is "10.8.0.0"
 * @mask {string}: must be consistant with subnet，default is "255.255.255.0"
 * @host {string|m}: server host, the public ip address of the device which is acted as openvpn server)
 * @return: 0=succeed, -1=openssl missing, -2=certificate file missing
 */
int set_vpn_config(json_object *input, json_object *output);

/**
 * create_vpn_certificate: generate Certificate Authority certificate and key
 * 
 * @force {int}: determine to re-create certificates, it is useful for certificate is expired
 * @return: 0=succeed, -1=missing parameter, -2=openssl missing -3=invalid type
 */
int create_vpn_certificate(json_object *input, json_object *output);

/**
 * get_ovpn: read the client ovpn configuration file
 *
 * #ovpn {string|m}
 * @return: 0=succeed
 */
int get_ovpn(json_object *input, json_object *output);
/**
 * get_file_status: get ovpn file status
 *
 * #success {bool|m}
 * @return: 0=succeed
 */
int get_file_status(json_object *input, json_object *output);

#endif
