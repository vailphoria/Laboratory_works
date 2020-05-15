---


---

<p> МИНИСТЕРСТВО НАУКИ  И ВЫСШЕГО ОБРАЗОВАНИЯ РОССИЙСКОЙ ФЕДЕРАЦИИ<br>
Федеральное государственное автономное образовательное учреждение высшего образования<br>
“КРЫМСКИЙ ФЕДЕРАЛЬНЫЙ УНИВЕРСИТЕТ им. В. И. ВЕРНАДСКОГО”<br>
ФИЗИКО-ТЕХНИЧЕСКИЙ ИНСТИТУТ<br>
Кафедра компьютерной инженерии и моделирования<br>
<br><br></p>
<h3 id="отчёт-по-лабораторной-работе-№1br-по-дисциплине-программирование">Отчёт по лабораторной работе №1<br> по дисциплине “Программирование”</h3>
<br>
<p>студентки 1 курса группы ПИ-б-о-191(2)<br>
Забелиной Валерии Павловны<br>
направления подготовки 09.03.04 “Программная инженерия”<br>
<br></p>
<table>
<tbody><tr><td>Научный руководитель<br> старший преподаватель кафедры<br> компьютерной инженерии и моделирования</td>
<td>(оценка)</td>
<td>Чабанов В.В.</td>
</tr>
</tbody></table>
<br><br>
<p>Симферополь, 2020</p>
<h2 id="лабораторная-работа-№1">Лабораторная работа №1</h2>
<p>Изучение базовых возможностей MS Visual Studio<br>
<br>
<strong>Цель:</strong> изучить основные возможности создания и отладки программ в IDE MS Visual Studio.<br>
<br>
<strong>Ход работы:</strong><br>
<br>
<strong>1. Как создать консольное приложение С++</strong><br>
Для создания консольного приложения C++ нужно открыть программу “Microsoft Visual Studio 2019” и в разделе “Файл”(сверху слева) выбрать<br>
“Создать”&gt;&gt;“Проект…” (рис.1) или нажать сочетание клавиш Ctrl+Shift+N.<br>
<img src="https://raw.githubusercontent.com/vailphoria/Laboratory_works/master/Lab1/Images_for_lab1/%D0%A0%D0%B8%D1%81.1%20%D0%A1%D0%BE%D0%B7%D0%B4%D0%B0%D0%BD%D0%B8%D0%B5%20%D0%BF%D1%80%D0%BE%D0%B5%D0%BA%D1%82%D0%B0.jpg" alt="Рис.1 Создание проекта"><br>
<em>рис.1: создание проекта</em><br>
<br>
<br>
В появившемся окне выбираем пункт “Консольное приложение” с пометкой “c++” и жмём “далее” (рис.2).<br>
<img src="https://raw.githubusercontent.com/vailphoria/Laboratory_works/master/Lab1/Images_for_lab1/%D0%A0%D0%B8%D1%81.2%20%D0%92%D1%8B%D0%B1%D0%BE%D1%80%20%D0%BF%D1%80%D0%BE%D0%B5%D0%BA%D1%82%D0%B0.JPG" alt="Рис.2 Выбор проекта"><br>
<em>рис.2: выбор шаблона</em><br>
<br>
<br>
После этого в графе “Имя проекта” вводим нужное имя нового файла-проекта и в графе “Расположение” указываем путь к папке, в которой хотим<br>
его сохранить, после этого необходимо нажать “Создать” в правом нижнем углу, подождать пока компьютер закончит создание проекта, содержащего<br>
консольное приложение(рис.3).<br>
<img src="https://raw.githubusercontent.com/vailphoria/Laboratory_works/master/Lab1/Images_for_lab1/%D0%A0%D0%B8%D1%81.3%20%D0%93%D0%BE%D1%82%D0%BE%D0%B2%D0%BE%D0%B5%20%D0%BA%D0%BE%D0%BD%D1%81%D0%BE%D0%BB%D1%8C%D0%BD%D0%BE%D0%B5%20%D0%BF%D1%80%D0%B8%D0%BB%D0%BE%D0%B6%D0%B5%D0%BD%D0%B8%D0%B5.JPG" alt="Рис.3 Консольное приложение"><br>
<em>рис.3: готовое консольное приложение</em><br>
<br>
<br>
<strong>2. Как изменить цветовую схему (оформление) среды</strong><br>
Для изменения цветового оформления среды нужно нажать Ctrl+Q для открытия поиска, ввести “Цветовые темы среды” и перейти по первому<br>
выпавшему пункту (рис.4).<br>
<img src="https://raw.githubusercontent.com/vailphoria/Laboratory_works/master/Lab1/Images_for_lab1/%D0%A0%D0%B8%D1%81.4%20%D0%9F%D0%BE%D0%B8%D1%81%D0%BA.jpg" alt="Рис.4 Поиск"><br>
<em>рис.4: поиск</em><br>
<br>
<br>
В появившимся окне параметров открываем выпадающий список цветовых тем (рис.5) и выбираем на свой вкус.<br>
<img src="https://raw.githubusercontent.com/vailphoria/Laboratory_works/master/Lab1/Images_for_lab1/%D0%A0%D0%B8%D1%81.5%20%D0%A6%D0%B2%D0%B5%D1%82%D0%BE%D0%B2%D1%8B%D0%B5%20%D1%82%D0%B5%D0%BC%D1%8B.JPG" alt="Рис.5 Цветовые темы"><br>
<em>рис.5: цветовые темы</em><br>
<br>
<br>
После выбора нужно нажать “OK” и Microsoft Visual Studio изменит свое цветовое оформление.<br>
<br>
<strong>3.Как закомментировать/раскомментировать блок кода средствами VS</strong><br>
Для того что бы закомментировать часть кода в Microsoft Visual Studio необходимо ее выделить и нажать сочетание клавиш Ctrl+K, Ctrl+C.<br>
<img src="https://raw.githubusercontent.com/vailphoria/Laboratory_works/master/Lab1/Images_for_lab1/%D0%A0%D0%B8%D1%81.6%20%D0%97%D0%B0%D0%BA%D0%BE%D0%BC%D0%B5%D0%BD%D1%82%D0%B8%D1%80%D0%BE%D0%B2%D0%B0%D0%BD%D0%BD%D1%8B%D0%B9%20main.JPG" alt="Рис.6 Закомментированный main"><br>
<em>рис.6: закомментированный main</em><br>
<br>
<br>
Для раскомментирования выделенного текста нужно нажать Ctrl+K, Ctrl+U.<br>
<br>
<strong>4.Как открыть в проводнике Windows папку с проектом средствами VS</strong><br>
Для открытия папки с проектом находясь в VS необходимо нажать сочетание клавиш Ctrl+O, открывающие проводник Windows. В проводнике<br>
выбрать необходимый файл и нажать “Открыть” (рис.7).<br>
<img src="https://raw.githubusercontent.com/vailphoria/Laboratory_works/master/Lab1/Images_for_lab1/%D0%A0%D0%B8%D1%81.7%20%D0%9F%D1%80%D0%BE%D0%B2%D0%BE%D0%B4%D0%BD%D0%B8%D0%BA.JPG" alt="Рис.7 проводник"><br>
<em>рис.7: проводник</em><br>
<br>
<br>
<strong>5.Какое расширение файла-проекта используется в VS</strong><br>
В Microsoft Visual Studio 2019 для файлов-проектов используется расширение “.vcxproj”, а для решения “.sin”<br>
<br>
<strong>6.Как запустить код без отладки</strong><br>
Для запуска кода без отладки нужно в разделе “Отладка” (рис.8) выбрать пункт “Запуск без отладки”<br>
<img src="https://raw.githubusercontent.com/vailphoria/Laboratory_works/master/Lab1/Images_for_lab1/%D0%A0%D0%B8%D1%81.8%20%D0%A0%D0%B0%D0%B7%D0%B4%D0%B5%D0%BB%20%D0%9E%D1%82%D0%BB%D0%B0%D0%B4%D0%BA%D0%B0.jpg" alt="Рис.8 Раздел &quot;Отладка&quot;"><br>
<em>рис.8: раздел “отладка”</em><br>
<br>
<br>
или нажать сочетание клавиш Ctrl+F5<br>
<br>
<strong>7.Как запустить код в режиме отладки</strong><br>
Для запуска кода в режиме отладки нужно в разделе “Отладка” (рис.8) выбрать пункт “Начать отладку” или нажать клавишу F5<br>
<br>
<strong>8.Как установить/убрать точку останова (breakpoint)</strong><br>
Чтобы установить/убрать точку останова в Microsoft Visual Studio, нужно щелкнуть в левом поле рядом с интересующей строкой кода.<br>
Также для этого можно поместить указатель в нужную строку и нажать клавишу F9.<br>
<strong>9.Создание и отладка программы</strong><br>
Я создала программу с данным кодом:\</p>
<pre class=" language-c"><code class="prism ++ language-c"><span class="token macro property">#<span class="token directive keyword">include</span> <span class="token string">&lt;iostream&gt;</span></span>

<span class="token keyword">int</span> <span class="token function">main</span><span class="token punctuation">(</span><span class="token punctuation">)</span>
<span class="token punctuation">{</span>
	<span class="token keyword">int</span> i<span class="token punctuation">;</span>
	i <span class="token operator">=</span> <span class="token number">5</span><span class="token punctuation">;</span>
	std<span class="token punctuation">:</span><span class="token punctuation">:</span>cout <span class="token operator">&lt;&lt;</span> i<span class="token punctuation">;</span>
	<span class="token keyword">return</span> <span class="token number">0</span><span class="token punctuation">;</span>
<span class="token punctuation">}</span>
</code></pre>
<p>и поставила breakpoint в строчке 5(int i;) и 6(i = 5;)<br>
После этого я запустила приложение в режиме отладки с помощью клавиши F5 и, перемещаясь по ходу исполнения команд с помощью кнопки<br>
“Шаг с обходом”(F5), проверила значение переменной i в строках 5 и 6.<br>
В строке 5, переменная i имела значение -858993460 (рис.9), а в строке 6 изменила его на 5.<br>
<img src="https://raw.githubusercontent.com/vailphoria/Laboratory_works/master/Lab1/Images_for_lab1/%D0%A0%D0%B8%D1%81.9%20%D0%9E%D1%82%D0%BB%D0%B0%D0%B4%D0%BA%D0%B0%20%D0%BF%D1%80%D0%BE%D0%B3%D1%80%D0%B0%D0%BC%D0%BC%D1%8B%201.JPG" alt="Рис.9 Отладка программы 1"><br>
<em>рис.9: отладка программы"</em><br>
<br>
<br>
<strong>9.Создание и отладка измененной программы</strong><br>
Я изменила программу таким образом:\</p>
<pre class=" language-c"><code class="prism ++ language-c"><span class="token macro property">#<span class="token directive keyword">include</span> <span class="token string">&lt;iostream&gt;</span></span>

<span class="token keyword">int</span> <span class="token function">main</span><span class="token punctuation">(</span><span class="token punctuation">)</span>
<span class="token punctuation">{</span>
	<span class="token keyword">double</span> i<span class="token punctuation">;</span>
	i <span class="token operator">=</span> <span class="token number">5</span><span class="token punctuation">;</span>
	std<span class="token punctuation">:</span><span class="token punctuation">:</span>cout <span class="token operator">&lt;&lt;</span> i<span class="token punctuation">;</span>
	<span class="token keyword">return</span> <span class="token number">0</span><span class="token punctuation">;</span>
<span class="token punctuation">}</span>
</code></pre>
<p>и поставила breakpoint в строчке 5(int i;) и 6(i = 5;)<br>
После этого я запустила приложение в режиме отладки с помощью клавиши F5 и, перемещаясь по ходу исполнения команд с помощью кнопки<br>
“Шаг с обходом”(F5), проверила значение переменной i в строках 5 и 6.<br>
В строке 5, переменная i имела значение -9.2559631349317831e+61 (рис.10), а в строке 6 изменила его на 5.0000000000000000.<br>
<img src="https://raw.githubusercontent.com/GachiGucciGhoul/Laboratory_works/master/Lab1/Images_for_lab1/%D0%A0%D0%B8%D1%81.10%20%D0%9E%D1%82%D0%BB%D0%B0%D0%B4%D0%BA%D0%B0%20%D0%BF%D1%80%D0%BE%D0%B3%D1%80%D0%B0%D0%BC%D0%BC%D1%8B%202.JPG" alt="Рис.10 Отладка программы 2"><br>
<em>рис.10: отладка программы 2"</em><br>
<br>
<br>
<strong>Вывод:</strong> в ходе выполнения данной лабораторной работы я изучила основные возможности создания программ в Microsoft Visual Studio 2019<br>
и приобрела навыки использования средств отладки программы, тем самым достигнув поставленной цели.</p>

