#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // ���ͷ�ļ���ʹ�� isdigit ����
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

// �ͷ������ڴ�ĺ���
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
    printf(" ��������������������ӭʹ�����п���ȡ����ϵͳ�������������������� \n");
    printf(" �� �� \n");
    printf(" �� ��ѡ�������Ŀ�� �� \n");
    printf(" �� 1.����Ա��¼ 2.�ͻ���¼ �� \n");
    printf(" �� 0.�˳�ϵͳ �� \n");
    printf(" ���������������������������������������������������������������� \n");
}

void menumanager() {
    system("cls");

    printf("\n\n\n");
    printf(" ����������������ӭʹ�����п���ȡ����ϵͳ----����Ա������������ \n");
    printf(" �� �� \n");
    printf(" �� ��ѡ�������Ŀ�� �� \n");
    printf(" �� 1.������п� 2.ע��������Ϣ �� \n");
    printf(" �� 3.���ʧ 4.��ӿͻ���Ϣ �� \n");
    printf(" �� 5.���� 6.������¼ �� \n");
    printf(" | 7.��ʧ 8.�˳�ϵͳ | \n");
    printf(" �������������������������������������������������������������� \n");
}

void menucustom() {
    system("cls");

    printf("\n\n\n");
    printf(" ����������������ӭʹ�����п���ȡ����ϵͳ----�ͻ��������������� \n");
    printf(" �� �� \n");
    printf(" �� ��ѡ�������Ŀ�� �� \n");
    printf(" �� 1.�޸����� 2.��� �� \n");
    printf(" �� 3.ȡ�� 4.ת�� �� \n");
    printf(" �� 5.����� 6.�齻�� �� \n");
    printf(" | 7.��ѯ���� 8.�˳�ϵͳ | \n");
    printf(" �������������������������������������������������������������� \n");
}
int main(int argc, char* argv[]) {
    int flag = 1;
    int index1, index2;
    int loginreturn;

    while (flag == 1) {
        system("cls");
        firstmenu();
        printf("��������Ҫѡ��Ĳ���:\n");
        scanf("%d", &index1);

        switch (index1) {
        case 1:
            loginreturn = login();
            if (loginreturn == 1) {
                menumanager();
                int innerFlag = 1;
                while (innerFlag == 1) {
                    printf("��ѡ��Ҫ���еĲ���\n");
                    scanf("%d", &index1);

                    switch (index1) {
                    case 1:
                        add_bank_card();
                        break;
                    case 2:
                        cancel_account();
                        break;
                    case 3:
                        resolve_loss(); // �޸�Ϊ���ʧ�ĺ���
                        break;
                    case 4:
                        add_customer();
                        break;
                    case 5:
                        open_account();
                        break;
                    case 6:
                        display_account_records(); // �޸�Ϊ��ʾ������¼�ĺ���
                        break;
                    case 7:
                        block_account();
                        break;
                    case 8:
                        innerFlag = 0;
                        printf("Exiting...\n");
                        break;
                    default:
                        printf("������ѡ��\n");
                    }
                    system("pause");
                }
            }
            break;
        case 2:
            loginreturn = login();
            if (loginreturn == 2) {
                menucustom();
                int innerFlag = 1; // �����ڲ�ѭ����־
                while (innerFlag == 1) { // �޸��ڲ�ѭ������
                    printf("��ѡ��Ҫ���еĲ���\n");
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
            flag = 0; // ���� flag Ϊ����ֵ���˳�ѭ��
            printf("Exiting...\n");
            break;
        default:
            printf("������ѡ��\n");
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

    printf("\t\t�����������û�id:");
    printf("\t");
    scanf("%s", uname);

    printf("\t\t���������ĵ�½����:");
    int k = 0;
    while (k < 19) {
        tch = getch(); // ʹ�� getch() ���� getchar()

        if (tch == 13) { // ���س�����������������
            break;
        }
        else if (tch == 8) { // ����˸��
            if (k > 0) {
                printf("\b \b"); // ɾ��ǰһ���ַ����ƶ����
                k--;
            }
        }
        else if (isalnum(tch)) { // ��������ĸ������
            putchar('*'); // ���ǺŴ�����ʾ�����ַ�
            upassword[k++] = tch;
        }
    }

    upassword[k] = '\0'; // ȷ���ַ����� null ��β
    printf("\n");
    printf("\t\t��ѡ�������Ϣ��1������Ա 2���ͻ�\n");
    scanf("%d", &rolename);

    if (rolename == 1) {
        strcpy(role, "manager");
    }
    else if (rolename == 2) {
        strcpy(role, "customr");
    }
    else {
        printf("��Ч�������Ϣѡ��\n");
        return -1;
    }

    if (strcmp(upassword, password1) == 0 && strcasecmp(role, "manager") == 0) {
        strcpy(lmanagerid, uname);
        return 1;
    }

    if (strcmp(upassword, password1) == 0 && strcasecmp(role, "customr") == 0) {
        return 2;
    }
    else {
        printf("�ʺŻ��������\n");
        getchar();
        return -1;
    }
}

void change_password()
{
    char id_number[20];
    char new_password[20];
    printf("����������֤��: ");
    scanf("%s", id_number);
    struct Customer* current_customer = customer_head;
    while (current_customer != NULL) {
        if (strcmp(current_customer->id_number, id_number) == 0) {
            printf("�������������: ");
            scanf("%s", new_password);
            // ��ʵ��Ӧ���У�������Ҫ��Ӹ�������밲ȫ�Լ�����֤
            strcpy(current_customer->password, new_password);
            printf("�ɹ��޸�����\n");
            return;
        }
        current_customer = current_customer->next;
    }
    printf("δ�ҵ����û�\n");
}

void withdraw() {
    char card_number[20];
    double withdraw_amount; // Change the type to double
    char location[50];
    printf("��������Ŀ���: ");
    scanf("%s", card_number);

    printf("������ȡ����: "); // Correct the prompt
    scanf("%lf", &withdraw_amount); // Change the format specifier to %lf
    // ����ȡ���¼�ڵ�
    struct Transaction* new_transaction = (struct Transaction*)malloc(sizeof(struct Transaction));
    if (new_transaction == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    // ����ȡ���¼��Ϣ
    strcpy(new_transaction->card_number, card_number);
    new_transaction->timestamp = time(NULL);
    new_transaction->amount = -withdraw_amount; // ������ʾȡ��
    strcpy(new_transaction->location, "ATM"); // ����ȡ��ص���ATM��ʵ���п�����Ҫ�û�����������߼�
    new_transaction->next = NULL;
    // ���¼�¼��ӵ�����ͷ��
    new_transaction->next = transaction_head;
    transaction_head = new_transaction;
    printf("�ɹ�ȡ��\n Amount: %.2lf\n", withdraw_amount);
}


void deposit() {
    char card_number[20];
    double deposit_amount;
    char location[50];
    printf("��������Ŀ���: ");
    scanf("%s", card_number);
    printf("���������˻�: ");
    scanf("%lf", &deposit_amount);
    printf("���������ַ: ");
    scanf("%s", location);
    // ��������¼�ڵ�
    struct Transaction* new_transaction = (struct Transaction*)malloc(sizeof(struct Transaction));
    if (new_transaction == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    // ���ô���¼��Ϣ
    strcpy(new_transaction->card_number, card_number);
    new_transaction->timestamp = time(NULL);
    new_transaction->amount = deposit_amount;
    strcpy(new_transaction->location, location);
    new_transaction->next = NULL;
    // ���¼�¼��ӵ�����ͷ��
    new_transaction->next = transaction_head;
    transaction_head = new_transaction;
    printf("���ɹ�\n Amount: %.2lf\n", deposit_amount);
}

void make_transfer() {
    char receiver_card_number[20];
    char sender_card_number[20];
    double transfer_amount;
    printf("�����뱻ת���˿���: ");
    scanf("%s", receiver_card_number);
    // ��ʵ��Ӧ���У�������Ҫ��ӿ��ŵ���Ч�Լ�����֤
    printf("������ת���˿���: ");
    scanf("%s", sender_card_number);
    // ��ʵ��Ӧ���У�������Ҫ��ӿ��ŵ���Ч�Լ�����֤
    printf("������ת�����˻�: ");
    scanf("%lf", &transfer_amount);
    // ��ʵ��Ӧ���У�������Ҫ��Ӹ����ת����Ϣ����֤�ʹ���
    // ����ת�˼�¼�ڵ�
    struct Transfer* new_transfer = (struct Transfer*)malloc(sizeof(struct Transfer));
    if (new_transfer == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    // ����ת�˼�¼��Ϣ
    strcpy(new_transfer->receiver_card_number, receiver_card_number);
    strcpy(new_transfer->sender_card_number, sender_card_number);
    new_transfer->timestamp = time(NULL);
    new_transfer->amount = transfer_amount;
    new_transfer->next = NULL;
    // ���¼�¼��ӵ�����ͷ��
    new_transfer->next = transfer_head;
    transfer_head = new_transfer;
    printf("���׳ɹ�\n Amount: %.2lf\n", transfer_amount);
}

void check_balance() {
    char card_number[20];

    printf("��������Ŀ���: ");
    scanf("%s", card_number);

    // ����������֤��ȷ�����ŵĺϷ���

    struct Customer* current_customer = customer_head;

    while (current_customer != NULL) {
        if (strcmp(current_customer->card_number, card_number) == 0) {
            printf("������Ϊ: %.2lf\n", current_customer->balance); // �޸�Ϊ %.2lf �Ա���С������λ
            return;
        }

        current_customer = current_customer->next;
    }

    printf("δ�ҵ�ƥ�俨�ŵĿͻ�\n");
}


void display_transactions() {
    struct Transaction* current_transaction = transaction_head;
    printf("\n������ʷ\n");
    while (current_transaction != NULL) {
        printf("Card Number: %s, Time: %s, Amount: %.2lf, Location: %s\n",
            current_transaction->card_number, asctime(localtime(&current_transaction->timestamp)),
            current_transaction->amount, current_transaction->location);
        current_transaction = current_transaction->next;
    }
}

void display_transfers() {
    struct Transfer* current_transfer = transfer_head;
    printf("\n������ʷ\n");
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

    printf("������������: ");
    scanf("%d", &new_card->bank_code); // ����Ϊ %d
    printf("������������: ");
    scanf("%s", new_card->bank_name);
    printf("���뿨��: ");
    scanf("%s", new_card->card_number); // ����Ϊ %s
    new_card->next = NULL;

    // �������п���ӵ�����ͷ��
    new_card->next = bank_head;
    bank_head = new_card;

    printf("������гɹ�\n");
}

void cancel_account() {
    char id_number[20];
    printf("������Ҫע�������֤��\n ");
    scanf("%s", id_number);
    struct AccountInfo* current_account = account_head;
    struct AccountInfo* prev_account = NULL;
    while (current_account != NULL) {
        if (strcmp(current_account->id_number, id_number) == 0) {
            if (current_account->is_closed) {
                printf("Account is already closed.\n");
                return;
            }
            current_account->is_closed = 1; // ��״̬���Ϊ��ע��
            // ��ʵ��Ӧ���У�������Ҫִ���������������紦������
            printf("ע��������Ϣ�ɹ�\n");
            return;
        }
        prev_account = current_account;
        current_account = current_account->next;
    }
    printf("ע��ʧ��\n");
}

void unblock_account() {
    char id_number[20];
    printf("������Ҫ���ʧID ");
    scanf("%s", id_number);
    struct AccountInfo* current_account = account_head;
    while (current_account != NULL) {
        if (strcmp(current_account->id_number, id_number) == 0) {
            if (current_account->is_blocked) {
                current_account->is_blocked = 0; // ���ʧ
                printf("�ɹ����ʧ\n");
                break;
            }
            else {
                printf("û���ҵ���Ҫ���ʧ��ID\n");
                return;
            }
        }
        current_account = current_account->next;
    }
    printf("���ʧʧ��\n");
}

void add_customer() {
    struct Customer* new_customer = (struct Customer*)malloc(sizeof(struct Customer));
    if (new_customer == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    printf("���������֤��: ");
    scanf("%s", new_customer->id_number);
    printf("����������: ");
    scanf("%s", new_customer->name);
    printf("�������Ա�: ");
    scanf("%s", new_customer->gender);
    printf("�������ַ: ");
    scanf("%s", new_customer->address);
    printf("������绰����: ");
    scanf("%s", new_customer->phone);
    printf("����������: ");
    scanf("%s", new_customer->password);
    new_customer->next = NULL;
    // ���¿ͻ���ӵ�����ͷ��
    new_customer->next = customer_head;
    customer_head = new_customer;
    printf("�ɹ���ӿͻ�\n");
}

void open_account() {
    struct AccountInfo* new_account = (struct AccountInfo*)malloc(sizeof(struct AccountInfo));
    if (new_account == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    printf("���������֤��: ");
    scanf("%s", new_account->id_number);
    printf("���������п�����: ");
    scanf("%s", new_account->card_number);
    printf("�������ʼ����: ");
    scanf("%s", new_account->initial_password);
    printf("�������ܱ�����: ");
    scanf("%s", new_account->security_question);
    printf("�������ܱ���: ");
    scanf("%s", new_account->security_answer);
    new_account->balance = 0.0;
    new_account->is_blocked = 0; // Ĭ�ϲ���ʧ
    new_account->is_closed = 0; // Ĭ��δע��
    new_account->next = NULL;
    // ���¿�����Ϣ��ӵ�����ͷ��
    new_account->next = account_head;
    account_head = new_account;
    printf("�����ɹ�\n");
}

void display_accounts() {
    struct AccountInfo* current_account = account_head;
    printf("\nAccounts List\n");
    while (current_account != NULL) {
        printf("���֤��: %s\n ����: %s\n �Ƿ��ʧ: %s\n �Ƿ�ע��: %s\n",
            current_account->id_number, current_account->card_number,
            current_account->is_blocked ? "Yes" : "No",
            current_account->is_closed ? "Yes" : "No");
        current_account = current_account->next;
    }
}

void block_account() {
    char id_number[20];
    printf("��������Ҫ��ʧ�����֤��: ");
    scanf("%s", id_number);
    struct AccountInfo* current_account = account_head;
    while (current_account != NULL) {
        if (strcmp(current_account->id_number, id_number) == 0) {
            if (current_account->is_blocked) {
                printf("�˻��Ѿ���ʧ\n");
                return;
            }
            current_account->is_blocked = 1; // ��ʧ
            printf("��ʧ�ɹ�\n");
            return;
        }
        current_account = current_account->next;
    }
    printf("��ʧʧ��\n");
}

