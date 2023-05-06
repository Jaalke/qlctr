""" 
The CSS provider doesn't use the id="" field in the glade file - instead
it only looks at the <property name="name"> tag. This script adds that tag
for all the buttons in the glade file that have a specified id field.
"""

with open("glade.txt") as glade:

    button_lines = []
    button_ids = []
    lines = glade.readlines()

    for i, line in enumerate(lines):
        if "object class=\"GtkButton\" id" in line:
            id = line.strip().replace("<object class=\"GtkButton\" id=\"", "").rstrip("\">")
            button_lines.append(i)
            button_ids.append(id)

    for i, line in enumerate(button_lines):
        id_line = f"                  <property name=\"name\">{button_ids[i]}</property>\n"
        lines.insert(line + i + 1, id_line)

with open("glade_edited.txt", 'w') as glade_edited:
    glade_edited.writelines(lines)