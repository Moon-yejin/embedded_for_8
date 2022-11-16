#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <asm/uaccess.h>

#define HELLO_MAJOR_NUM 888
#define HELLO_NAME "hello"

static int hello_open (struct inode *node, struct file *pfile)
{
	printk("hello_open enter! \r \n");
	return 0;
}

static ssize_t hello_read(struct file *pfile, char __user *pBuff, size_t size, loff_t *filepos)
{
	char arrData[4] = {'1','2','3','4'};
	printk ("hello_read enter! \r \n");
	if (size >= 4)
	{
		copy_to_user(pBuff, arrData, 4);
		return 4;
	}
	return 0;
}

static ssize_t hello_write(struct file *pfile, char __user *pBuff, size_t size, loff_t *filepos)
{
        char arrData[4];
        printk ("hello_write enter! \r \n");
        if (size >= 4)
        {
                copy_from_user(arrData, pBuff, 4);
                return 4;
        }
        return 0;
}

static int hello_release(struct inode *node, struct file *pfile)
{
	printk("hello_release enter! \r \n");
	return 0;
}

// IO CONTROL 추가
static char array[2000];

static long dev_ioctl (struct file *filp, unsigned int cmd, unsigned long arg)
{
	int count = 0; // N byte
	int k = 0;
	if (_IOC_TYPE (cmd) != 0x88)
	{
		printk ("Wrong Majic number! \r \n");
		return -1;
	}
	switch (_IOC_NR (cmd))
	{
		case 89: printk ("-> %d \r \n", _IOC_SIZE (cmd));
			 copy_from_user(array, arg, _IOC_SIZE (cmd));
			 break;

		case 88: printk ("-> %d \r \n", _IOC_SIZE (cmd));
			 copy_from_user(&count, arg, _IOC_SIZE (cmd));
			 for (k=0; k < count; k++)
			 {
				 printk ("%d", array[k]);
				 printk ("\r \n");
				 break;
			 }

		default: break;
	}
}

static const struct file_operations hello_fops = {
	.owner = THIS_MODULE,
	.open = hello_open,
	.read = hello_read,
	.write = hello_write,
	.release = hello_release,
	.unlocked_ioctl = hello_ioctl,
};

int flagRegisterSuccess = 0;

int __init init_hello(void)
{
	int ret;
	printk("Hello, team 8! \r \n");
	ret = register_chrdev(888, "hello", &hello_fops);
	if (ret < 0)
	{
		printk("Hello register_chrdev fail \r \n");
		return ret;
	}

	flagRegisterSuccess = 1;
	return 0;
}

void __exit exit_hello(void)
{
	if (flagRegisterSuccess)
	{
		flagRegisterSuccess = 0;
		unregister_chrdev(888, "hello");
	}
	printk ("Good bye, team 8! \r \n");
}

module_init(init_hello);
module_exit(exit_hello);

MODULE_LICENSE("GPL");
