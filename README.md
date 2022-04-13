# 1071710_proj_1
## 此次project包含內容如下
- [x] 程式碼 - 1071710_proj_1.asm
- [x] 輸入輸出範例數組 - 1071710_proj_1輸入輸出範例.docx
- [x] 說明文件 - README.md
### 其餘內容
* Test_C++_Program放置的是C++的測試程式，用於參考答案是否正確。將0 - 100的答案全數印出來
---
## 程式碼說明
---
### register的使用
本次的各個register的使用如下
 * a7 固定放 system call
 * a0 用於input和output的字串顯示
 * t0 放計算的解答
 * t1 - t3 分別放入 20、10、1的constant，因其function有x > 20；10 < x <= 20；1 < x <= 10； x = 0 ； x = 1的範圍設定
 * t4 則是固定放input之x number
### 基本的防呆範圍限制
首先，由於作業說明有要求基本的Input number x 有個限制範圍，為 x<=99 
因此只要輸入範圍大於99，則顯示**The input  number is greater than 99, please try again.**，要求使用者重新輸入。如下圖所示，此時直接輸入number就好，若條件符合就會開始計算！
- ![again](https://github.com/Ryan0911/1071710_proj_1/blob/main/image/again.png)
### 各個Basic Block之說明：
 * main ： 顯示 Input a number:
 * limit ： 讀取一個整數，初始化之後會放入解答的t0與放入input number的t4，將**t1設置為100以用於判斷使用者是否輸入超過99**，若使用者超出99，則進入limit2的區塊，反之則input number為合法，進入start區塊。
 * limit2 ： 輸入不合法，顯示要求使用者重新輸入並跳回limit區塊
 * start ： 將t1 - t3 分別放入20、10、1 以供後續比對，並跳入function區塊，將答案計算完成後無條件跳入exit區塊。
 * function ： 
   - 跳入function的第一件事情：將基本argument與return address存入stack，由於只用到word大小，因此stack pointer只需下拉開出8個空間。
   - 接下來我將跳入function會由上至下進行判斷的六個區塊分別命名為block 1 - 6，將依照計算過後的x進入他們相應的block，如下圖片所示：
   - ![function](https://github.com/Ryan0911/1071710_proj_1/blob/main/image/function.png)
 * block1 ： 將x乘以2，放入t5，並將其計算結果加到t0(最後顯示的解)，而t6放入之後要做除法的5，因為之後要跳入的function需要先將x除以5，再跳入function，之後計算完後統一回至functionExit區塊，結束本區塊的任務。
 * block2 ： 將t4也就是放x的地方減2跳入function，回來之後必須重新load放在stack內的t4，拿回原本的x，再做減3進入function，之後統一回到functionExit，結束本區塊任務。
 * block3 ： 與block2做的事情一模一樣，只是將-2改成-1；-3改成-2。
 * block4 ： 此區塊單純許多，直接把t0加1，之後就可以回到functionExit結束本區塊任務啦。
 * block5 ： 與block4一樣，這次是加5。
 * block6 ： 與block4一樣，減一。
 * functionExit ： 這一區塊統一處理各個block要離開function時所需要做的回復動作！將return address與t4回復為跳入前的數值，並回復stack空間，之後跳回跳入前的address！
 * exit ： 這就是function計算完後，處理後續動作的區塊！先將Output字串**The damage:** 顯示出來，之後將計算完後的解答t0放到a0，並system call Printint，將剛剛放入a0的值print出來，最後再system call 10 結束本次project program！ 
