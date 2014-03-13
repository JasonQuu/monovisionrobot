/********************************************************************
* �ļ���  �� ��ˮ��.c
* ����    :  �ó���ʵ��LED����ˮ����ʾ��
			 �ó�������ѧϰ LED��ˮ�� �Ŀ��Ʒ�����
			 �������ǵ��õ� intrins.h �еĺ���ʵ�ֵ�ѭ����λ��		 
* ������  �� ������2009��8��27��
* �汾��  �� 1.0
***********************************************************************/
#include<reg52.h>
#include<intrins.h>
#define uchar unsigned char
#define uint  unsigned int

/********************************************************************
* ���� : Delay()
* ���� : ��ʱ,��ʱʱ��Ϊ 10ms * del
* ���� : del
* ��� : ��
***********************************************************************/
void Delay(uint del)
{
	uint i,j;
	for(i=0; i<del; i++)
	for(j=0; j<1827; j++)   
	;
}

/********************************************************************
* ���� : Main()
* ���� : ʵ�ֵƵ���˸
* ���� : ��
* ��� : ��
* ˵�� ��Ҳ����ʹ����1�ĵķ������ر������
***********************************************************************/
void Main(void)
{
	uchar i;
	P2 = 0x00;
	while(1)
	{
		P0 = 0x7f;					//P0.7����
		for(i=0; i<7; i++)			//��λ7��
		{
			P0 = _cror_(P0, 1);		//_crol_()���������intrins.h�ж����ˣ�����ѭ������
			Delay(15);
		}
		P0 = 0xfe;
		for(i=0; i<7; i++)
		{
			P0 = _crol_(P0, 1);	    //����ѭ������
			Delay(15);
		}

	}
}