#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <py_url.h>

int main(int argc, char* argv[])
{

	int         port = 0;
	int         len  = 0;
	const char* url  = "https//www.abcdef.com/action?name=彼得&age=32&pageno=3&pagesize=10";
	char site[1024];
	char file[1024];
	char encode_url_buff[1024];
	char decode_url_buff[1024];

	fprintf(stdout, "url=%s\n", url);
	
	if(py_parse_url(url, site, sizeof(site), &port, file, sizeof(file))!=0){
		assert(0);
	}
	fprintf(stdout, "site = %s\n", site);
	fprintf(stdout, "port = %d\n", port);
	fprintf(stdout, "file = %s\n", file);

	len = strlen(url);
	encode_url(url, len, encode_url_buff, sizeof(encode_url_buff));
	fprintf(stdout, "encode_url = %s\n", encode_url_buff);
	
	
	len = strlen(encode_url_buff);
	decode_url(encode_url_buff, len, decode_url_buff, sizeof(decode_url_buff));
	fprintf(stdout, "decode_url = %s\n", decode_url_buff);

	return 0;
}
