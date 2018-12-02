int deletestudent(Students* massiv, int n) 
{ 
int student; 
int ist = 0; 
n = n-1; 
printf("Введите номер студента, данные о котором вы хотите удалить: "); 
while(ist == 0) 
{ 
if(scanf("%d", &student) < 1) 
{ 
printf("Номер студента - это число! Попробуйте еще: "); 
scanf("%*[^\n]"); 
scanf("%*c"); 
} 
else 
{ 
if(student < 1 || student > n+1) 
{ 
printf("Такого студента не существует! Попробуйте еще: "); 
} 
else 
{ 
ist = 1; 
} 
} 
} 
if(student == 1) 
{ 
for(int i = 0; i < n; i++) 
{ 
strcpy(massiv[i].fio, massiv[i+1].fio); 
massiv[i].no_z = massiv[i+1].no_z; 
massiv[i].yearb = massiv[i+1].yearb; 
massiv[i].mark = massiv[i+1].mark; 
massiv[i].money = massiv[i+1].money; 
} 
} 
if(student != 1 && student != n+1) 
{ 
for(int i = student-1; i < n; i++) 
{ 
strcpy(massiv[i].fio, massiv[i+1].fio); 
massiv[i].no_z = massiv[i+1].no_z; 
massiv[i].yearb = massiv[i+1].yearb; 
massiv[i].mark = massiv[i+1].mark; 
massiv[i].money = massiv[i+1].money; 
} 
} 
printf("Данные успешно удалены!\n"); 
return n; 
} 

Students* fnplasstudent(Students* plusmassiv, Students* massiv, int n) 
{ 
int ist = 0; 
for(int i = 0; i < n-1; i++) 
{ 
strcpy(massiv[i].fio, plusmassiv[i].fio); 
massiv[i].no_z = plusmassiv[i].no_z; 
massiv[i].yearb = plusmassiv[i].yearb; 
massiv[i].mark = plusmassiv[i].mark; 
massiv[i].money = plusmassiv[i].money; 
} 
while(ist == 0) 
{ 
printf("\nВведите фамилию студента, которая состоит только из английских букв: "); 
scanf("%s", massiv[n-1].fio); 
for(int j = 0; j < strlen(massiv[n-1].fio); j++) 
{ 
if(((massiv[n-1].fio[j] > 64) && (massiv[n-1].fio[j] < 91)) || ((massiv[n-1].fio[j] > 96) && (massiv[n-1].fio[j] < 123))) 
{ 
ist = 1; 
} 
else 
{ 
ist = 0; 
printf("Фамилия студента не может содержать русские буквы, цифры или другие символы, кроме английских букв!\n"); 
j = strlen(massiv[n-1].fio); 
} 
} 
} 
ist = 0; 
printf("Введите номер зачетки студента: "); 
while(ist == 0) 
{ 
if(scanf("%d", &massiv[n-1].no_z) < 1) 
{ 
printf("Номер зачетки состоит из цифр! Введите номер зачетки студента: "); 
scanf("%*[^\n]"); 
scanf("%*c"); 
} 
else 
{ 
if(massiv[n-1].no_z <= 0) 
{ 
printf("Номер зачетки не может быть отрицательным! Введите номер зачетки студента: "); 
} 
else 
{ 
ist = 1; 
} 
} 
} 
ist = 0; 
printf("Введите год рождения студента: "); 
while(ist == 0) 
{ 
if(scanf("%d", &massiv[n-1].yearb) < 1) 
{ 
printf("Год рождения состоит из цифр! Введите год рождения студента: "); 
scanf("%*[^\n]"); 
scanf("%*c"); 
} 
else 
{ 
if(massiv[n-1].yearb <= 0) 
{ 
printf("Год рождения не может быть отрицательным! Введите год рождения студента: "); 
} 
else 
{ 
ist = 1; 
} 
} 
} 
ist = 0; 
printf("Введите средний бал за последнюю сессию студента: ");
while(ist == 0) 
{ 
if(scanf("%f", &massiv[n-1].mark) < 1) 
{ 
printf("Cредний бал за последнюю сессию состоит из цифр! Введите средний бал за последнюю сессию студента: "); 
scanf("%*[^\n]"); 
scanf("%*c"); 
} 
else 
{ 
if(massiv[n-1].mark < 0 || massiv[n-1].mark > 5) 
{ 
printf("Cредний бал за последнюю сессию не может быть отрицательным или больше 5! Введите средний бал за последнюю сессию студента: "); 
} 
else 
{ 
ist = 1; 
if(roundf(massiv[n-1].mark*10)/10 < 3.75) 
{ 
massiv[n-1].money = 0; 
} 
if(roundf(massiv[n-1].mark*10)/10 >= 3.75 && roundf(massiv[n-1].mark*10)/10 < 4.5) 
{ 
massiv[n-1].money = 100; 
} 
if(roundf(massiv[n-1].mark*10)/10 >= 4.5 && roundf(massiv[n-1].mark*10)/10 < 4.75) 
{ 
massiv[n-1].money = 150; 
} 
if(roundf(massiv[n-1].mark*10)/10 >= 4.75) 
{ 
massiv[n-1].money = 200; 
} 
} 
} 
} 
printf("Данные успешно заполнены!\n"); 
return massiv; 
}