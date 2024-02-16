#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // 添加头文件以使用 isdigit 函数
#include <time.h>
#include <conio.h>

struct Customer {
char id_number[20];
char card_number[20];
char name[50];
char gender[10];
char address[100];
char phone[20];
char password[20];
struct Customer* next;
};

struct BankCard {
int bank_code;
char bank_name[50];
char card_number[20];
struct BankCard* next;
};

struct Transaction {
char card_number[20];
time_t timestamp;
double amount;
char location[50];
struct Transaction* next;
};

struct AccountInfo {
char id_number[20];
char card_number[20];
char initial_password[20];
char security_question[100];
char security_answer[100];
double balance;
int is_blocked;
int is_closed;
struct AccountInfo* next;
};

struct LossRecord {
char card_number[20];
time_t timestamp;
struct LossRecord* next;
};

struct Transfer {
char receiver_card_number[20];
char sender_card_number[20];
time_t timestamp;
double amount;
struct Transfer* next;
};

struct Customer* customer_head = NULL;
struct Transaction* transaction_head = NULL;
struct Transfer* transfer_head = NULL;
struct BankCard* bank_head = NULL;
struct LossRecord* loss_record_head = NULL;
struct AccountInfo* account_head = NULL;

void change_password();
void deposit();
void withdraw();
void make_transfer();
void check_balance();
void display_transactions();
void display_transfers();
void add_bank_card();
void cancel_account();
void resolve_loss();
void add_customer();
void display_account_records();
void display_loss_records();
void unblock_account();
void open_account();
void display_accounts();
void block_account();
void firstmenu();
void menumanager();
void menucustom();
int loginreturn();
int login();

char lmanagerid[20];

// 释放链表内存的函数
void free_customer_list(struct Customer* head) {
struct Customer* current = head;
struct Customer* next;

while (current != NULL) {
next = current->next;
free(current);
current = next;
}
}

void free_transaction_list(struct Transaction* head) {
struct Transaction* current = head;
struct Transaction* next;

while (current != NULL) {
next = current->next;
free(current);
current = next;
}
}

void free_transfer_list(struct Transfer* head) {
struct Transfer* current = head;
struct Transfer* next;

while (current != NULL) {
next = current->next;
free(current);
current = next;
}
}

void free_bank_list(struct BankCard* head) {
struct BankCard* current = head;
struct BankCard* next;

while (current != NULL) {
next = current->next;
free(current);
current = next;
}
}

void free_loss_record_list(struct LossRecord* head) {
struct LossRecord* current = head;
struct LossRecord* next;

while (current != NULL) {
next = current->next;
free(current);
current = next;
}
}

void free_account_list(struct AccountInfo* head) {
struct AccountInfo* current = head;
struct AccountInfo* next;

while (current != NULL) {
next = current->next;
free(current);
current = next;
}
}

void firstmenu() {
printf("\n\n\n");
printf(" ┌──────——欢迎使用银行卡存取管理系统─────────┐ \n");
printf(" │ │ \n");
printf(" │ 请选择操作项目： │ \n");
printf(" │ 1.管理员登录 2.客户登录 │ \n");
printf(" │ 0.退出系统 │ \n");
printf(" └────────────—─────────────────┘ \n");
}

void menumanager() {
system("cls");

printf("\n\n\n");
printf(" ┌──────欢迎使用银行卡存取管理系统----管理员─────┐ \n");
printf(" │ │ \n");
printf(" │ 请选择操作项目： │ \n");
printf(" │ 1.添加银行卡 2.注销开户信息 │ \n");
printf(" │ 3.解挂失 4.添加客户信息 │ \n");
printf(" │ 5.开户 6.开户记录 │ \n");
printf(" | 7.挂失 8.退出系统 | \n");
printf(" └─────────────────────────────┘ \n");
}

void menucustom() {
system("cls");

printf("\n\n\n");
printf(" ┌──────欢迎使用银行卡存取管理系统----客户—─────┐ \n");
printf(" │ │ \n");
printf(" │ 请选择操作项目： │ \n");
printf(" │ 1.修改密码 2.存款 │ \n");
printf(" │ 3.取款 4.转账 │ \n");
printf(" │ 5.查余额 6.查交易 │ \n");
printf(" | 7.查询交易 8.退出系统 | \n");
printf(" └─────────────────────────────┘ \n");
}
int main(int argc, char* argv[]) {
int flag = 1;
int index1, index2;
int loginreturn;

while (flag == 1) {
system("cls");
firstmenu();
printf("请输入你要选择的操作:\n");
scanf("%d", &index1);

switch (index1) {
case 1:
loginreturn = login();
if (loginreturn == 1) {
menumanager();
int innerFlag = 1;
while (innerFlag == 1) {
printf("请选择要进行的操作\n");
scanf("%d", &index1);

switch (index1) {
case 1:
add_bank_card();
break;
case 2:
cancel_account();
break;
case 3:
resolve_loss(); // 修改为解挂失的函数
break;
case 4:
add_customer();
break;
case 5:
open_account();
break;
case 6:
display_account_records(); // 修改为显示开户记录的函数
break;
case 7:
block_account();
break;
case 8:
innerFlag = 0;
printf("Exiting...\n");
break;
default:
printf("请重新选择\n");
}
system("pause");
}
}
break;
case 2:
loginreturn = login();
if (loginreturn == 2) {
menucustom();
int innerFlag = 1; // 新增内部循环标志
while (innerFlag == 1) { // 修改内部循环条件
printf("请选择要进行的操作\n");
scanf("%d", &index2);
switch (index2) {
case 1:
change_password();
break;
case 2:
deposit();
break;
case 3:
withdraw();
break;
case 4:
make_transfer();
break;
case 5:
check_balance();
break;
case 6:
display_transactions();
break;
case 7:
display_transfers();
break;
case 8:
printf("Exiting...\n");
break;
default:
printf("Invalid choice. Please try again.\n");
}
}
return 0;
}
break;
case 0:
flag = 0; // 设置 flag 为其他值以退出循环
printf("Exiting...\n");
break;
default:
printf("请重新选择\n");
}
system("pause");
}

free_customer_list(customer_head);
free_transaction_list(transaction_head);
free_transfer_list(transfer_head);
free_bank_list(bank_head);
free_loss_record_list(loss_record_head);
free_account_list(account_head);

return 0;
}

int login() {
int rolename;
char uname[20];
char role[10];
char tch, upassword[20];
char password1[20] = "123456";

printf("\t\t请输入您的用户id:");
printf("\t");
scanf("%s", uname);

printf("\t\t请输入您的登陆密码:");
int k = 0;
while (k < 19) {
    tch = getch(); // 使用 getch() 代替 getchar()
    
    if (tch == 13) { // 检测回车键，结束密码输入
        break;
    } else if (tch == 8) { // 检测退格键
        if (k > 0) {
            printf("\b \b"); // 删除前一个字符并移动光标
            k--;
        }
    } else if (isalnum(tch)) { // 仅允许字母和数字
        putchar('*'); // 用星号代替显示密码字符
        upassword[k++] = tch;
    }
}

upassword[k] = '\0'; // 确保字符串以 null 结尾
printf("\n");
printf("\t\t请选择身份信息，1：管理员 2：客户\n");
scanf("%d", &rolename);

if (rolename == 1) {
strcpy(role, "manager");
} else if (rolename == 2) {
strcpy(role, "customr");
} else {
printf("无效的身份信息选择\n");
return -1;
}

if (strcmp(upassword, password1) == 0 && strcasecmp(role, "manager") == 0) {
strcpy(lmanagerid, uname);
return 1;
}

if (strcmp(upassword, password1) == 0 && strcasecmp(role, "customr") == 0) {
return 2;
} else {
printf("帐号或密码错误！\n");
getchar();
return -1;
}
}

void change_password() 
{
char id_number[20];
char new_password[20];
printf("输入你的身份证号: ");
scanf("%s", id_number);
struct Customer* current_customer = customer_head;
while (current_customer != NULL) {
if (strcmp(current_customer->id_number, id_number) == 0) {
printf("输入你的新密码: ");
scanf("%s", new_password);
// 在实际应用中，可能需要添加更多的密码安全性检查和验证
strcpy(current_customer->password, new_password);
printf("成功修改密码\n");
return;
}
current_customer = current_customer->next;
}
printf("未找到该用户\n");
}

void withdraw() {
char card_number[20];
double withdraw_amount; // Change the type to double
char location[50];
printf("请输入你的卡号: ");
scanf("%s", card_number);

printf("请输入取款金额: "); // Correct the prompt
scanf("%lf", &withdraw_amount); // Change the format specifier to %lf
// 创建取款记录节点
struct Transaction* new_transaction = (struct Transaction*)malloc(sizeof(struct Transaction));
if (new_transaction == NULL) {
printf("Memory allocation failed.\n");
return;
}
// 设置取款记录信息
strcpy(new_transaction->card_number, card_number);
new_transaction->timestamp = time(NULL);
new_transaction->amount = -withdraw_amount; // 负数表示取款
strcpy(new_transaction->location, "ATM"); // 假设取款地点是ATM，实际中可能需要用户输入或其他逻辑
new_transaction->next = NULL;
// 将新记录添加到链表头部
new_transaction->next = transaction_head;
transaction_head = new_transaction;
printf("成功取款\n Amount: %.2lf\n", withdraw_amount);
}


void deposit() {
char card_number[20];
double deposit_amount;
char location[50];
printf("请输入你的卡号: ");
scanf("%s", card_number);
printf("请输入存款账户: ");
scanf("%lf", &deposit_amount);
printf("请输入存款地址: ");
scanf("%s", location); 
// 创建存款记录节点
struct Transaction* new_transaction = (struct Transaction*)malloc(sizeof(struct Transaction));
if (new_transaction == NULL) {
printf("Memory allocation failed.\n");
return;
}
// 设置存款记录信息
strcpy(new_transaction->card_number, card_number);
new_transaction->timestamp = time(NULL);
new_transaction->amount = deposit_amount;
strcpy(new_transaction->location, location);
new_transaction->next = NULL;
// 将新记录添加到链表头部
new_transaction->next = transaction_head;
transaction_head = new_transaction;
printf("存款成功\n Amount: %.2lf\n", deposit_amount);
}

void make_transfer() {
char receiver_card_number[20];
char sender_card_number[20];
double transfer_amount;
printf("请输入被转账人卡号: ");
scanf("%s", receiver_card_number);
// 在实际应用中，可能需要添加卡号的有效性检查和验证
printf("请输入转账人卡号: ");
scanf("%s", sender_card_number);
// 在实际应用中，可能需要添加卡号的有效性检查和验证
printf("请输入转账人账户: ");
scanf("%lf", &transfer_amount);
// 在实际应用中，可能需要添加更多的转账信息的验证和处理
// 创建转账记录节点
struct Transfer* new_transfer = (struct Transfer*)malloc(sizeof(struct Transfer));
if (new_transfer == NULL) {
printf("Memory allocation failed.\n");
return;
}
// 设置转账记录信息
strcpy(new_transfer->receiver_card_number, receiver_card_number);
strcpy(new_transfer->sender_card_number, sender_card_number);
new_transfer->timestamp = time(NULL);
new_transfer->amount = transfer_amount;
new_transfer->next = NULL;
// 将新记录添加到链表头部
new_transfer->next = transfer_head;
transfer_head = new_transfer;
printf("交易成功\n Amount: %.2lf\n", transfer_amount);
}

void check_balance() {
char card_number[20];

printf("请输入你的卡号: ");
scanf("%s", card_number);

// 进行输入验证，确保卡号的合法性

struct Customer* current_customer = customer_head;

while (current_customer != NULL) {
if (strcmp(current_customer->card_number, card_number) == 0) {
printf("你的余额为: %.2lf\n", current_customer->balance); // 修改为 %.2lf 以保留小数点两位
return;
}

current_customer = current_customer->next;
}

printf("未找到匹配卡号的客户\n");
}


void display_transactions() {
struct Transaction* current_transaction = transaction_head;
printf("\n交易历史\n");
while (current_transaction != NULL) {
printf("Card Number: %s, Time: %s, Amount: %.2lf, Location: %s\n",
current_transaction->card_number, asctime(localtime(&current_transaction->timestamp)),
current_transaction->amount, current_transaction->location);
current_transaction = current_transaction->next;
}
}

void display_transfers() {
struct Transfer* current_transfer = transfer_head;
printf("\n交易历史\n");
while (current_transfer != NULL) {
printf("Receiver's Card Number: %s, Sender's Card Number: %s, Time: %s, Amount: %.2lf\n",
current_transfer->receiver_card_number, current_transfer->sender_card_number,
asctime(localtime(&current_transfer->timestamp)), current_transfer->amount);
current_transfer = current_transfer->next;
}
}

void add_bank_card() {
struct BankCard* new_card = (struct BankCard*)malloc(sizeof(struct BankCard));
if (new_card == NULL) {
printf("Memory allocation failed.\n");
return;
}

printf("输入银行密码: ");
scanf("%d", &new_card->bank_code); // 修正为 %d
printf("输入银行名称: ");
scanf("%s", new_card->bank_name);
printf("输入卡号: ");
scanf("%s", new_card->card_number); // 修正为 %s
new_card->next = NULL;

// 将新银行卡添加到链表头部
new_card->next = bank_head;
bank_head = new_card;

printf("添加银行成功\n");
}

void cancel_account() {
char id_number[20];
printf("输入需要注销的身份证号\n ");
scanf("%s", id_number);
struct AccountInfo* current_account = account_head;
struct AccountInfo* prev_account = NULL;
while (current_account != NULL) {
if (strcmp(current_account->id_number, id_number) == 0) {
if (current_account->is_closed) {
printf("Account is already closed.\n");
return;
}
current_account->is_closed = 1; // 将状态标记为已注销
// 在实际应用中，可能需要执行其他操作，例如处理余额等
printf("注销开户信息成功\n");
return;
}
prev_account = current_account;
current_account = current_account->next;
}
printf("注销失败\n");
}

void unblock_account() {
char id_number[20];
printf("输入需要解挂失ID ");
scanf("%s", id_number);
struct AccountInfo* current_account = account_head;
while (current_account != NULL) {
if (strcmp(current_account->id_number, id_number) == 0) {
if (current_account->is_blocked) {
current_account->is_blocked = 0; // 解挂失
printf("成功解挂失\n");
break;
} else {
printf("没有找到需要解挂失的ID\n");
return;
}
}
current_account = current_account->next;
}
printf("解挂失失败\n");
}

void add_customer() {
struct Customer* new_customer = (struct Customer*)malloc(sizeof(struct Customer));
if (new_customer == NULL) {
printf("Memory allocation failed.\n");
return;
}
printf("请输入身份证号: ");
scanf("%s", new_customer->id_number);
printf("请输入名字: ");
scanf("%s", new_customer->name);
printf("请输入性别: ");
scanf("%s", new_customer->gender);
printf("请输入地址: ");
scanf("%s", new_customer->address);
printf("请输入电话号码: ");
scanf("%s", new_customer->phone);
printf("请输入密码: ");
scanf("%s", new_customer->password);
new_customer->next = NULL;
// 将新客户添加到链表头部
new_customer->next = customer_head;
customer_head = new_customer;
printf("成功添加客户\n");
}

void open_account() {
struct AccountInfo* new_account = (struct AccountInfo*)malloc(sizeof(struct AccountInfo));
if (new_account == NULL) {
printf("Memory allocation failed.\n");
return;
}
printf("请输入身份证号: ");
scanf("%s", new_account->id_number);
printf("请输入银行卡名称: ");
scanf("%s", new_account->card_number);
printf("请输入初始密码: ");
scanf("%s", new_account->initial_password);
printf("请输入密保问题: ");
scanf("%s", new_account->security_question);
printf("请输入密保答案: ");
scanf("%s", new_account->security_answer);
new_account->balance = 0.0;
new_account->is_blocked = 0; // 默认不挂失
new_account->is_closed = 0; // 默认未注销
new_account->next = NULL;
// 将新开户信息添加到链表头部
new_account->next = account_head;
account_head = new_account;
printf("开户成功\n");
}

void display_accounts() {
struct AccountInfo* current_account = account_head;
printf("\nAccounts List\n");
while (current_account != NULL) {
printf("身份证号: %s\n 卡号: %s\n 是否挂失: %s\n 是否注销: %s\n",
current_account->id_number, current_account->card_number,
current_account->is_blocked ? "Yes" : "No",
current_account->is_closed ? "Yes" : "No");
current_account = current_account->next;
}
}

void block_account() {
char id_number[20];
printf("请输入需要挂失的身份证号: ");
scanf("%s", id_number);
struct AccountInfo* current_account = account_head;
while (current_account != NULL) {
if (strcmp(current_account->id_number, id_number) == 0) {
if (current_account->is_blocked) {
printf("账户已经挂失\n");
return;
}
current_account->is_blocked = 1; // 挂失
printf("挂失成功\n");
return;
}
current_account = current_account->next;
}
printf("挂失失败\n");
}

