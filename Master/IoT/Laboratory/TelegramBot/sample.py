import logging


from telegram import Update
from telegram.ext import ApplicationBuilder, CommandHandler, ContextTypes, MessageHandler, filters

from config import BOTKEY, interval
from random import uniform

logging.basicConfig(level=logging.DEBUG,
                    format='%(asctime)s - %(name)s - %(levelname)s - %(message)s')

logger = logging.getLogger()
logger.setLevel(logging.DEBUG)

# Define a few command handlers. These usually take the two arguments update and
# context. Error handlers also receive the raised TelegramError object in error.
async def cmd_start(update: Update, context: ContextTypes.DEFAULT_TYPE) -> None:
    #await update.message.reply_text(f'Hello {update.effective_user.first_name}')
    chatid = update.effective_chat.id

    await context.bot.send_message(chat_id=chatid, text=f'Hello {update.effective_user.first_name}, I am ready!')
    await context.bot.send_message(chat_id=chatid, text=f'I will start sending new value every {interval} seconds')

    context.job_queue.run_repeating(send_randomvalue, interval, chat_id=chatid, name=str(chatid))

async def cmd_help(update: Update, context: ContextTypes.DEFAULT_TYPE) -> None:
    """Send a message when the command /help is issued."""
    await update.message.reply_text('Help!')

async def cmd_echo(update: Update, context: ContextTypes.DEFAULT_TYPE) -> None:
    """Send a message when the command /help is issued."""
    #await update.message.reply_text(update.message.text)
    chatid = update.effective_chat.id
    receveidmessage = update.message.text
    sendmessage = 'I receveid ' + receveidmessage

    await context.bot.send_message(chat_id=chatid, text=sendmessage)


async def cmd_stop(update: Update, context: ContextTypes.DEFAULT_TYPE) -> None:
    
    chatid = update.effective_chat.id

    await context.bot.send_message(chat_id=chatid, text='Bye')

    job = context.job_queue.get_jobs_by_name(str(chatid))
    job[0].schedule_removal()

def main():
    """Start the bot."""
    # Create the ApplicationBuilder and pass it your bot's token.
    app = ApplicationBuilder().token(BOTKEY).build()

    # add an handler for each command
    # start and help are usually defined
    app.add_handler(CommandHandler("start", cmd_start)) 
    app.add_handler(CommandHandler("help", cmd_help))
    app.add_handler(CommandHandler("stop"),cmd_stop)

    #app.add_handler(MessageHandler(filters.TEXT & ~filters.COMMAND, cmd_echo))
    # Start the Bot (polling of messages)
    # this call is non-blocking
    app.run_polling()



async def send_randomvalue(context):
    val = int(uniform(0,255))
    chat_id = context.job.chat_id
    await context.bot.send_message(chat_id=chat_id, text =f'New value detected: ' + str(val))   

if __name__ == '__main__':
    main()