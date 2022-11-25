#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <asm/uaccess.h>

#define HELLO_MAJOR_NUM 888
#define HELLO_NAME "hello"

static char array[2000] = {0,};
int cnt = 0;

static int hello_open (struct inode *node, struct file *pfile)
{
	printk(" hello_open enter! \n");
	return 0;
}

static ssize_t hello_read(struct file *pfile, char __user *pBuff, size_t size, loff_t *filepos)
{
        printk (" hello_read enter! \n");
        if (size >= 4)
        {
		*filepos = 0;
                copy_to_user(pBuff, &array[*filepos], size);
                return size;
        }
        return 0;
}


static ssize_t hello_write(struct file *pfile, const char __user *pBuff, size_t size, loff_t *filepos)
{
	int i = 0;
        printk (" hello_write enter! \n");
        if (size >= 4)
	{

		*filepos = 0;
                copy_from_user(&array[*filepos], pBuff, size);
                return size;
		for (i=0; i < 4; i++)
		{
			printk(" %c", array[i]);
		}
        }
        return 0;
}

// IO CONTROL 추가
static long hello_ioctl (struct file *filp, unsigned int cmd, unsigned long arg)
{
//	int cnt = 0;
	int k = 0;
	if (_IOC_TYPE (cmd) != 0x88)
	{
		printk ("Wrong Majic number! \r \n");
		return -1;
	}
	switch (_IOC_NR (cmd))
	{
		case 89: printk(" IOCTL Size: %d\n", _IOC_SIZE(cmd)); // should be 20
			 copy_from_user(array, arg, _IOC_SIZE(cmd));
			 break;

		case 88: printk(" IOCTL Size: %d\n", _IOC_SIZE(cmd)); // should be 4
			 copy_from_user(&cnt, arg, _IOC_SIZE(cmd));
			 for (k=0; k < cnt; k++)
			 {
				 printk("%d", array[k]);
			 }
			 printk("\n");
                         break;

		default: break;
	}
}

static int hello_release(struct inode *node, struct file *pfile)
{
        printk(" hello_release enter! \n");
        return 0;
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
	printk(" Hello, team 8! \r \n");
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
	printk (" Good bye, team 8! \r \n");
}

module_init(init_hello);
module_exit(exit_hello);

MODULE_LICENSE("GPL");
