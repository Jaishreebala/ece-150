#include <iostream>
#include <cassert>
#include "project_1.hpp"
#include <stdlib.h>
// Function declarations
int main();
void print_program();
bool does_delimiter_match( char del );
bool do_delimiters_nest();
// Function definitions
int main()
{
	print_program();
	std::cout << does_delimiter_match( '(' ) << std::endl;
	std::cout << does_delimiter_match( '[' ) << std::endl;
	std::cout << does_delimiter_match( '{' ) << std::endl;
	std::cout << do_delimiters_nest() << std::endl;
	return 0;
}
// Your function definitions go here
void print_program()
{
	ece150::start_reading_file();
	while(ece150::at_eof()==false)
		std::cout<<ece150::get_next_character();
}


bool does_delimiter_match( char del )
{
	bool result = true;
	if(del!='('&&del!='{'&&del!='[')
		result = false ;
	int count=0;
	ece150::start_reading_file();
	while(!ece150::at_eof())
	{
		char chk=ece150::get_next_character();
		if(chk==del)
			count++;
		else
		{//start else
		if((del=='('&& chk==')')||(del=='{'&&chk=='}')||(del=='['&&chk==']'))
		{
			if(count==0)
			{
				std::cout<<"Unmatched "<<chk<<std::endl;
				result = false ;
			}
			else
				count--;
		}
		}//closes else
	}//closes while statement
	if(count>0)
	{
		std::cout<<std::endl<<"Missing ";
		result = false ;
		for(int k=count; k>0; k--)
		{
			if (del=='(')
				std::cout<<")";
			if (del=='{')
				std::cout<<"}";
			if (del=='[')
				std::cout<<"]";
		}
		std::cout << std::endl;
	}
	return result;
}//closes main function


bool do_delimiters_nest()
{
	bool result=true;
	ece150::start_reading_file();
	ece150::initialize_table();
		while(ece150::at_eof()==false)
		{
			char chk = ece150::get_next_character();
			if(chk == '(' || chk == '{' || chk == '[')
				ece150::place_character( chk );
			else if(chk == ')' || chk == '}' || chk == ']')
			{
				char right_char = ece150::get_right_most_character();
				if(chk == ')' && right_char == '(' )
					ece150::erase_right_most_character();
				else if ( chk == '}' && right_char == '{')
					ece150::erase_right_most_character();
				else if (chk == ']' && right_char == '[')
					ece150::erase_right_most_character();
				else
				{
					std::cout<<"Unmatched " << chk <<std::endl;
					result = false;
				}
			}
		}//closes while ie, after end of file

		if(ece150::is_table_empty()==false)
		{
			result = false;
			std::cout<<"Missing ";
			while(ece150::is_table_empty()==false)
			{

				if(ece150::get_right_most_character()=='(')
				{	std::cout<<")"; 					ece150::erase_right_most_character();}
				else
				if(ece150::get_right_most_character()=='{')
				{	std::cout<<"}"; 					ece150::erase_right_most_character();}
				else if(ece150::get_right_most_character()=='[')
				{	std::cout<<"]";					ece150::erase_right_most_character();}
			}
			std::cout << std::endl;
		}
		return result;

}
