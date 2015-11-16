void SendColors(byte red, byte grn, byte blu)
{
  Wire.begin(); 
}
int filesize=9;

void print(int a);
int write(String a);
String file="aaa";
CardReader::CardReader()
{
   filesize = 0;
   print(write(filesize));
   write();
   write(file,b);
}
void CardReader::ls() 
{
  lsAction=LS_SerialPrint;
}
static void lcd_sdcard_print_menu();
void lcd_sdcard_print_menu(){
	lcd_sdcard_menu();
}