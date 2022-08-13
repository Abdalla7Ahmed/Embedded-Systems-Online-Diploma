

MEMORY 
{
	flash(RX) : ORIGIN = 0x08000000, LENGTH = 128K
	sram(RWX) : ORIGIN = 0x20000000, LENGTH = 20K
}

SECTIONS 
{
	.text :{
		*(.Vectors*)
		*(.text*)
	}>flash
	.bss :{
		*(.bss*)
	}>sram

}