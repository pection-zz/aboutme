function DH_table = DHTrans(p)

    DH_table = rot(p(1),'z')*trans(p(2),'z')*trans(p(3),'x')*rot(p(4),'x');
    
end