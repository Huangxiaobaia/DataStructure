#include <iostream>
using namespace std;

//�򻯰�Ͱ����
void test01()
{
	int t[11],i,j;
	for (i = 0; i < 11; i++)
		t[i] = 0;//��ʼ��

	for (i = 0; i < 5; i++)
	{
		cin >> j;
		t[j]++;
	}

	for (i = 0; i < 11; i++)
		for (j = 0; j < t[i]; j++)
			cout << i << " ";

}

//ð������
void test02()
{
	int t[100], n,i,j,temp;
	cout << "������n������" ;
	cin >> n;
	cout << "��ʼ���룺";
	for (i = 0; i < n; i++)
		cin >> t[i];

	for(i=0;i<n-1;i++)//��n-1��
		for(j=0;j<n-1-i;j++)//ÿ�˹��Ƚ�n-1-i��
			if (t[j] < t[j + 1])
			{
				temp = t[j];
				t[j] = t[j + 1];
				t[j + 1] = temp;
			}
	cout << "�����Ϊ��\n";
	for (i = 0; i < n; i++)
		cout << t[i] << " ";
}

//��������
int t[100];
void quicksort(int left, int right)
{
	int i = left, j = right;//�����ڱ�
	int p;
	if (left > right)return;
	int temp = t[left];//���û�׼��
	while (i != j)
	{
		while (i < j&&t[j] >= temp)
			j--;
		while (i < j&&t[i] <= temp)
			i++;
		if (i < j)
		{
			p = t[i];
			t[i] = t[j];
			t[j] = p;
		}
	}
	//��ʱi=j����׼����λ
	t[left] = t[i];
	t[i] = temp;
	//�����������ߵ�
	quicksort(left, i - 1);
	quicksort(i+1, right);
	return;
}

void test03()
{
	int n,i;
	cout << "������n������";
	cin >> n;
	cout << "��ʼ���룺";
	for (i = 0; i < n; i++)
		cin >> t[i];

	quicksort(0,n-1);

	cout << "�����Ϊ��\n";
	for (i = 0; i < n; i++)
		cout << t[i] << " ";
}

//С������
void test04()
{
	int n, i,length=1,q[100],j=0;
	cout << "����n��ͬѧ������飺";
	cin >> n;
	cout << "ÿλͬѧϲ���鼮��ISBN�ţ�";
	for (i = 0; i < n; i++)
		cin >> t[i];

	quicksort(0, n - 1);
	q[0] = t[0];
	for (i = 1; i < n; i++)
	{
		if (t[i] != t[i - 1])
		{
			length++;
			q[++j] = t[i];
		}
	}

	cout << "��Ҫ��ı�����" << length << endl;
	cout << "ÿ�����ISBN�ţ�" << endl;
	for (i = 0; i < length; i++)
		cout << q[i] << " ";
}


int main()
{
	//test01();
	//test02();
	//test03();
	test04();
	return 0;
}