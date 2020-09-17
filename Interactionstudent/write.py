
def write_txtfile(Name,Text):
    text_file = open(Name+'.txt', "w")

    text_file.write(Text)

    text_file.close()

write_txtfile('Mike',"kwai")
