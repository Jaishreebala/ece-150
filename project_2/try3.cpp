/*#include<iostream>
#include<cmath>

unsigned char *encode( unsigned char *plaintext, unsigned long key );
char *decode( char *cihpertext, unsigned long key );

unsigned char *encode( unsigned char *plaintext, unsigned long key )
{
	unsigned char s[256];
	std::size_t strlen;
	unsigned int i{0}, j{0}, a{0};
	std::size_t newlen;


	for(strlen = 1; plaintext[strlen]; strlen++); //lenght without the null character

	newlen=(std::ceil(strlen/4.0))*4+1;


	char four_multiple[newlen];
	unsigned char xor_array[newlen];
	xor_array[newlen-1]= '\0';

	for(std::size_t k{0}; k<newlen; k++)
	{
		if(k<strlen){
			four_multiple[k]=plaintext[k];
		}else{
			four_multiple[k]='\0';
	}
	}
	for(std::size_t k{0}; k<256; k++)
	{
		s[k] = k;

	}
	while(a<256)
	{
		unsigned int k=i%64;
		j= (j+s[i]+((key>>k)&1L))%256;
		unsigned int temp=s[j];
		s[j]=s[i];
		s[i]=temp;
		i=(i+1)%256;
		a++;
	}

	std::cout<<static_cast<unsigned int>(xor_array[newlen-1])<<std::endl;
	for(std::size_t k{0}; k<(newlen-1); k++)
	{

		i=(i+1)%256;
		j=(j+s[i])%256;
		unsigned char temp=s[j];
		s[j]=s[i];
		s[i]=temp;
		std::size_t r= (s[i]+s[j])%256;
		unsigned char R=s[r];
//		std::cout<< static_cast<unsigned int>(R)<<" "<<static_cast;
		xor_array[k]= R ^ four_multiple[k];
	}
	//for(std::size_t k{0}; k<newlen;k++)
//	{
		//std::cout<<static_cast<unsigned int>(xor_array[k])<<" ";
	//}


	//ASCII ARMOUR//
	std::size_t base_85_len{5*(newlen/4) + 1};
	unsigned int base_85;
	unsigned char *armour_arr{ new unsigned char[base_85_len]{}};


	for (std::size_t x{0}; x<(newlen/4); x++)
	{
		base_85=(xor_array[4*x]<<24)+(xor_array[4*x+1]<<16)+(xor_array[4*x+2]<<8)+(xor_array[4*x+3]);
		armour_arr[5*x+4]=(base_85%85) +'!';
		base_85/=85;
		armour_arr[5*x+3]=(base_85%85) +'!';
		base_85/=85;
		armour_arr[5*x+2]=(base_85%85) +'!';
		base_85/=85;
		armour_arr[5*x+1]=(base_85%85) +'!';
		base_85/=85;
		armour_arr[5*x]=(base_85%85) +'!';
		base_85/=85;
	}
	armour_arr[5*base_85_len]='\0';
//print armour

	//for(std::size_t y{0}; y<base_85_len; y++)
		//std::cout<<armour_arr[y];
	return armour_arr;
}

int main(){
	unsigned char str0[]{ "Hello world!" };
	std::cout << "\"" << str0 << "\"" << std::endl;
	unsigned char * ciphertext = encode( str0, 51323 );
	std::cout<< "\"" << ciphertext << "\"" << std::endl;
	return 0;
}
*/
