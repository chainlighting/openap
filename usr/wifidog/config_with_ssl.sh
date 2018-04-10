LOCAL_DIR=$(pwd)
LOCAL_SSL=$(pwd)/../wolfssl-3.14.0
LOCAL_SSL_LIB="${LOCAL_SSL}/src/"
LOCAL_CFLAGS="-I${LOCAL_SSL}"
LOCAL_LDFLAGS="-L${LOCAL_SSL_LIB}"
LOCAL_CPPFLAGS="-I${LOCAL_SSL}"
# make wolfssl as .so and with tlsv1.0/SNI support
cd ${LOCAL_SSL};
make clean;
./configure --enable-shared=yes --enable-tlsv10=yes --enable-oldtls=yes --enable-examples=no --enable-sni=yes --enable-inline=no $@;
make;
cd -;

# configure wifidog with wolfssl support
cd ${LOCAL_DIR};
CPPFLAGS="${LOCAL_CPPFLAGS}" CFLAGS="${LOCAL_CFLAGS}" LDFLAGS="${LOCAL_LDFLAGS}"  ./configure --enable-cyassl=yes --enable-shared=no $@;
cd -;

