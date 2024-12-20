//secretes.h

const char* mqtt_server = "alno9hvl48tuh-ats.iot.us-east-2.amazonaws.com";

// Amazon Root CA 1
static const char AWS_CERT_CA[] PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----
MIIDQTCCAimgAwIBAgITBmyfz5m/jAo54vB4ikPmljZbyjANBgkqhkiG9w0BAQsF
ADA5MQswCQYDVQQGEwJVUzEPMA0GA1UEChMGQW1hem9uMRkwFwYDVQQDExBBbWF6
b24gUm9vdCBDQSAxMB4XDTE1MDUyNjAwMDAwMFoXDTM4MDExNzAwMDAwMFowOTEL
MAkGA1UEBhMCVVMxDzANBgNVBAoTBkFtYXpvbjEZMBcGA1UEAxMQQW1hem9uIFJv
b3QgQ0EgMTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBALJ4gHHKeNXj
ca9HgFB0fW7Y14h29Jlo91ghYPl0hAEvrAIthtOgQ3pOsqTQNroBvo3bSMgHFzZM
9O6II8c+6zf1tRn4SWiw3te5djgdYZ6k/oI2peVKVuRF4fn9tBb6dNqcmzU5L/qw
IFAGbHrQgLKm+a/sRxmPUDgH3KKHOVj4utWp+UhnMJbulHheb4mjUcAwhmahRWa6
VOujw5H5SNz/0egwLX0tdHA114gk957EWW67c4cX8jJGKLhD+rcdqsq08p8kDi1L
93FcXmn/6pUCyziKrlA4b9v7LWIbxcceVOF34GfID5yHI9Y/QCB/IIDEgEw+OyQm
jgSubJrIqg0CAwEAAaNCMEAwDwYDVR0TAQH/BAUwAwEB/zAOBgNVHQ8BAf8EBAMC
AYYwHQYDVR0OBBYEFIQYzIU07LwMlJQuCFmcx7IQTgoIMA0GCSqGSIb3DQEBCwUA
A4IBAQCY8jdaQZChGsV2USggNiMOruYou6r4lK5IpDB/G/wkjUu0yKGX9rbxenDI
U5PMCCjjmCXPI6T53iHTfIUJrU6adTrCC2qJeHZERxhlbI1Bjjt/msv0tadQ1wUs
N+gDS63pYaACbvXy8MWy7Vu33PqUXHeeE6V/Uq2V8viTO96LXFvKWlJbYK8U90vv
o/ufQJVtMVT8QtPHRh8jrdkPSHCa2XV4cdFyQzR1bldZwgJcJmApzyMZFo6IQ6XU
5MsI+yMRQ+hDKXJioaldXgjUkK642M4UwtBV8ob2xJNDd2ZhwLnoQdeXeGADbkpy
rqXRfboQnoZsG4q5WTP468SQvvG5
-----END CERTIFICATE-----
)EOF";

// Device Certificate
static const char AWS_CERT_CRT[] PROGMEM = R"KEY(
-----BEGIN CERTIFICATE-----
MIIDWTCCAkGgAwIBAgIUEOdRiB4UW+skPxrX/IFelsUB8U4wDQYJKoZIhvcNAQEL
BQAwTTFLMEkGA1UECwxCQW1hem9uIFdlYiBTZXJ2aWNlcyBPPUFtYXpvbi5jb20g
SW5jLiBMPVNlYXR0bGUgU1Q9V2FzaGluZ3RvbiBDPVVTMB4XDTI0MTAyOTA3MTgx
OFoXDTQ5MTIzMTIzNTk1OVowHjEcMBoGA1UEAwwTQVdTIElvVCBDZXJ0aWZpY2F0
ZTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBAOuX4to5A3dE38c85zF0
JQb25P+6VMA8t/sVbUoKB4D8Xq9xzybSDGwsntGblxDdtCf7cXWqFhPwrsbVvuhd
nnEusy//VYGbKDi3RYNlCFPgCnKuuxOIjLpeCGJ30weej3iZPVrpuu3W5lrXlZBt
2pQ9L5plUlZkR66dv6zIQRd42lbaCuCD/LcM172ZB81vVv+CTbiBAX/M2Tw7LziR
3Ye0ZIj1+AqcZwNzJU3PSOlZvuZEUiOMjD7on+ntJCM4BI9sm/TWEXzQJy416Mio
rZl7RHlOq079HfQB6DW9YjtdrOAwQGVsjxGN4LFbXzvzIuWaSHIIs41d3A4C9vqz
T3ECAwEAAaNgMF4wHwYDVR0jBBgwFoAUfBlFIUmM57yozcMGWysQ0jc8HugwHQYD
VR0OBBYEFJG9N0ViucHenSDf4SHC2jU2PUjvMAwGA1UdEwEB/wQCMAAwDgYDVR0P
AQH/BAQDAgeAMA0GCSqGSIb3DQEBCwUAA4IBAQC2LOhUboI47IBv3Z0ksrbe66JQ
9MoPpXfALjtJcUWOJxUydOlRZ6iCAAGuY/2yitolLwwwgaGbjIRj1z1/KDd8JICV
1/nbYfZt+ZBL2/upBFeVeOp7QrXev7oq4cq3cFaLmBuvIZ3szZG2SMQbJmzVF14F
KsjnYRJXAQo/tSIEWEDpM7b07v3a1S+deOBqiuRHVS0znuxfvHPEn2c+D2k13FlG
BFLjKoHFiRRGXIIBUnVayFLF2jp7rpj6bowkf39LwMoGpysLP7ZuoJRiPYCenSyE
DqOXt6qD3GFx8JXqidLOdyUNvwosVL2iVP9tk9qVfXQatQuftWBs8xS05KDb
-----END CERTIFICATE-----
)KEY";

// Device Private Key
static const char AWS_CERT_PRIVATE[] PROGMEM = R"KEY(
-----BEGIN RSA PRIVATE KEY-----
MIIEowIBAAKCAQEA65fi2jkDd0TfxzznMXQlBvbk/7pUwDy3+xVtSgoHgPxer3HP
JtIMbCye0ZuXEN20J/txdaoWE/CuxtW+6F2ecS6zL/9VgZsoOLdFg2UIU+AKcq67
E4iMul4IYnfTB56PeJk9Wum67dbmWteVkG3alD0vmmVSVmRHrp2/rMhBF3jaVtoK
4IP8twzXvZkHzW9W/4JNuIEBf8zZPDsvOJHdh7RkiPX4CpxnA3MlTc9I6Vm+5kRS
I4yMPuif6e0kIzgEj2yb9NYRfNAnLjXoyKitmXtEeU6rTv0d9AHoNb1iO12s4DBA
ZWyPEY3gsVtfO/Mi5ZpIcgizjV3cDgL2+rNPcQIDAQABAoIBAD17atFGVbg3eirV
owQN6mfR4Ns39kwgzGazJc1PpruroM4qZkQcRu+oCV5sO1VEdnKEtQxe8doMUqBD
QcoEPIgPBuY8vUTQiAOdGH/8ytqQuklJfjrPxOISDiAcYy822vw/CXsDSiwti/oj
Dr4dXRCYkya40G8JRoe0VUQzEoGcITeTetYZ+jmkrYrwy6fSUV9+E5FDMxD5B+Hs
+hLuIPhX/ZczS3IWfpZ75ksiUBuMKhpUDyLfz/n6f9UOkYOH9F0CTmMeoDHXJXXP
wXBBC6rXKKClZXpMWLKGtipFcHH+16zNrageBU7TsmPAMP/tZofN9jK3G2lqrDWL
XEpYq00CgYEA92U01NhkA3ilEdm3r9eZg5wIxPOn6kqPEJZvLR5eX26zR+dtFFLG
KXWcyGo0KKLEhqyBfL6teHtNeh45euCYaR2RDToHc4As9TRBY70eWYbLyfbpis5q
c1WaYD4MerZnae7cdOoXhqky32t/2YUEgAM9HvgEInEOvFXmk2XgUMMCgYEA88mY
XLsKsvGx88nFUHeMrG3qcCBWNFGDwxCvu8Dl8bRYH2Hcq+VuQvzg7wXBERH3QE0R
SiGqTUKDhAquhMBg88HeBXcuTcAtE8GgeErGAe34osL3mm/uVNaaiDy64JzRHZKS
4O8lO7SpuBoY0hC0fkEPV7fRExYFbSk7RU4hW7sCgYBdUL9syXJwHMGmygiPOzOc
gO6N25oqtZThHN0yl5HhTVAyfwiV8eLtIH/S2Lxz13Fpmwf8la+5EklXFq93ud/D
RnPAGXNWDbLnip5fkKYx/rY/p/LPeKyOdGuWgdETOFopiv982g+lq4yU2WeQFKxt
3MrhM4vbseltALnIP1UtIQKBgQDuQJogHkghhCaG/C1TK9MWfUF+HYxCC1w7WmZ0
ltvjMX5iBTE16b6txxhJYRVDioxakjcQfQBEC3oepJXUdXMLJu/F5akiIWusgDJE
/cawAhNZdjOoAjYpQaa6+KcmdvvD7AiRvgZkaHbpzs9tFRhgv1KwRpwVDBN3kLE1
VVsymwKBgDan4hZ2NzV99YMIewe/zFNTIP13gj20lBYjZ2edEmVblOy6llkNsDqd
bHigoFTKcBbFuwcPtZBr1dJDiu5zuhJBfG/vplGoYQHKlVBhHy4AtXDGElRWYyoI
yLch3XEQIDo2v42Bx+VQYfOTHMZvSFi8CqDo9mGhix0Cg83wgdeH
-----END RSA PRIVATE KEY-----
)KEY";

//Enter the name of your AWS IoT thing, MyNewESP