#Чистим екран
cat("\014")

#Завантажити дані з файла hospital-data.csv в таблицю даних data
data <- read.csv(file="D:/_PROJECTS/_LAB/TI/_DATA/Лабораторні/hospital-data.csv", header=TRUE, sep=",")

#Перші 3 записи
head(data, n=3)
#Останні 3 записи
tail(data, n=3)

#Загальна інфа
summary(data)

#Графік
plot(data[13])

#Фільтрування
data[data$State=='AZ' & data$Emergency.Services=='No', ]
