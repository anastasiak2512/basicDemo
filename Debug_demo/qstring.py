import lldb

def utf16string_summary(value, *rest):
    str_data = value.GetChildMemberWithName("d").GetChildMemberWithName("data")
    if str_data is None:
        return '""'
    length_vo = value.GetChildMemberWithName("d").GetChildMemberWithName("size")
    length = length_vo.GetValueAsUnsigned(0)
    if length == 0:
        return '""'
    data = str_data.GetPointeeData(0, length)
    error = lldb.SBError()
    bytes = data.ReadRawData(error, 0, 2*length)
    return '"%s"' % (bytes.decode('utf-16').encode('utf-8'))

def __lldb_init_module(debugger, *rest):
    print "registering QString"
    summary = lldb.SBTypeSummary.CreateWithFunctionName("qstring.utf16string_summary")
    summary.SetOptions(lldb.eTypeOptionHideChildren)
    debugger.GetDefaultCategory().AddTypeSummary( lldb.SBTypeNameSpecifier("QString", False), summary )