#ifndef HEAD_H
#define HEAD_H
/*�����ͷ�ļ��У������жϱ�ʶ�� HEAD_H �Ƿ񱻶��������δ���������˵����ͷ�ļ���δ�μӹ����룬���Ǳ�������ĳ���Σ�
���ҶԱ�ʶ�� HEAD_H ���к궨�壬��Ǵ��ļ��μӹ����롣����ʶ�� HEAD_H ���������˵��ͷ�ļ��μӹ����룬���Ǳ�����
��������ĳ���Ρ������㲻����ɶ���point���ظ����壬��ֹ����*/

class point{
	public:
		point(float x=0,float y=0):x(x),y(y){ };
		float getX() const {return x;}
		float getY() const {return y;}
	private:
		float x,y;
};

#endif     //HEAD_H
