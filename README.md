Instructions for building a library:

1. Save the library.c and main.h files and the folder named .vscode in one folder
2. Go to the VS Code editor and open the newly created folder with files via "Open folder"
3. Open the library.c file and press Ctrl + Shift + B
4. After that, a window from the task selection items will appear on the top of the screen.
5. You need to select "build c_dll.dll
                       compiler: "gcc.exe" "
6. Then messages will appear in the terminal:
   "> Task execution: building c_dll.dll <"
7. Upon successful completion of the case, the notification will be notified:
   "The terminal will be reused for tasks, press any key to close it."

In order to import a library into a Python program, you need to save the library and your program in one folder.
You can use the following code to import:
        shared_lib_path = "./add.so"
        if platform.startswith ('win32'):
            shared_lib_path = "./library.dll"
        try:
            add_lib = CDLL (shared_lib_path)
            print ("Successfully uploaded!", add_lib)
        except as e:
            print (s)

Then, after a successful import, the message "Successfully uploaded!" Will be displayed. and the library can be used.
Example of using functions: result = add_lib.some_function (c_int (argument))

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Інструкція для білду бібліотеки:

1. Зберегти файли library.c та main.h і папку з назвою .vscode у одній папці
2. Зайти у редактор VS Code та через "Open Folder" відкрити щойно створену папку з файлами
3. Відкрити файл library.c та натиснути комбінацію клавіш Ctrl+Shift+B
4. Після цього зверху на екрані має з'явитися віконечко із пунктами вибору таску.
5. Потрібно вибрати "build c_dll.dll
                     compiler: "gcc.exe""
6. Далі в терміналі з'явиться повідомлення:
   ">Executing task: build c_dll.dll<"
7. Після успішного завершення білду, буде виведено повідомлення:
   "Terminal will be reused by tasks, press any key to close it."

Для того щоб імпортувати бібліотеку у програму на Python, потрібно зберегти бібліотеку і Вашу програму в одній папці.
Для імпорту можна використати наступний код:
        shared_lib_path = "./add.so"
        if platform.startswith('win32'):
            shared_lib_path = "./library.dll"
        try:
            add_lib = CDLL(shared_lib_path)
            print("Successfully loaded! ", add_lib)
        except Exception as e:
            print(e)

Тоді, після успішного імпорту, буде виведено повідомлення "Successfully loaded!" і бібліотеку можна буде використовувати.
Зразок використання функції: result = add_lib.some_function(c_int(argument))
