project('malloc', 'c',
        version : '1.0.0',
        default_options : ['warning_level=3', 'c_std=c11'])

sources = [
        'src/main.c',
        'src/allocation_table.c'
]

malloc = executable('malloc', sources, install : true)

test('test', malloc)
