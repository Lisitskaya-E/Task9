#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

main()
{
    int N;
    setlocale(LC_ALL,"Rus");
    printf("����� ������: \n");
    scanf("%d", &N);
    while(1){
            if (N==1)
    {
        int m,n;
        printf("M(�����) � N (��������): \n");
        scanf("%d%d",&m,&n);

        int m1[m][n];
        printf("������� ������:\n");
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                scanf("%d",&m1[i][j]);
        int a[m*n];
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                a[n*j + i] = m1[j][i];
        printf("\n");
        for (int i = 0; i < n*m; i++)
            printf("%4d ", a[i]);
        int m2[m][n];
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                m2[j][i] = a[n*j + i];
        printf("\n");
        for(int i = 0; i < m; ++i)
        {
            printf("\n");
            for(int j = 0; j < n; ++j)
                printf("%4d ",m2[i][j]);
        }
    }
    if (N == 2)
    {
        int m,n;
        printf("M(�����) � N (��������): \n");
        scanf("%d%d",&m,&n);

        int m1[m][n], m2[m][n];
                for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
            {
                m1[i][j]= abs(i-j)+1;
                m2[i][j] = 0;
            }
        printf("\n");
        for(int i = 0; i < m; ++i)
        {
            printf("\n");
            for(int j = 0; j < n; ++j)
                printf("%4d ",m1[i][j]);
        }
        printf("\n");

// ���������� ������� ������
        int i=0;
        int i1=0;
        int j1=1;
        int j = 0;
        int k=1;
        int i2 = i1%2*(2-i1%4); // �������, ����� i2 = 0, 1, 0, -1, 0, 1, 0, -1 ...(���� ��������� �� �������� ��� ���������� )
        int j2 = j1%2*(2-j1%4); // j2 = 1, 0, -1, 0, ... (���� ��������� �� ������)

        while (k <= n*m)
        {
            m2[i][j] = k;
            if (j2&&(j+j2 == -1 || j+j2 == n)) // ���� ����� �� ���� ������ �����������
            {

                j1+=1;
                i1+=1;

            }
            else if(j2&&(m2[i][j+j2] !=0)) // ���� ����� �� ����������� ��������� ������ �����������
            {
                j1+=1;
                i1+=1;
            }
            if (i2 &&(i+i2 == -1 || i+i2 == m))
            {
                j1+=1;
                i1+=1;
            }
            else if(i2&&(m2[i+i2][j] !=0 ))
            {
                i1+=1;
                j1+=1;
            }
            i2 = i1%2*(2-i1%4);
            j2 = j1%2*(2-j1%4);
            i+=i2;
            j+=j2;


            k+=1;

        }
        for(int i = 0; i < m; ++i)
        {
            printf("\n");
            for(int j = 0; j < n; ++j)
                printf("%4d ",m2[i][j]);
        }
    }
    printf("����� ������: \n");
    scanf("%d", &N);
    }
    return 0;
}


