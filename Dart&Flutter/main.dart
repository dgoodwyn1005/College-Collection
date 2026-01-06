import 'package:flutter/material.dart';
import 'package:provider/provider.dart';
import 'package:go_router/go_router.dart';
import 'contact_page.dart';
import 'edit_page.dart';
import 'details_page.dart';
import 'contact_provider.dart';

void main() {
  runApp(
    ChangeNotifierProvider(
      create: (context) => ContactProvider(),
      child: const MainApp(),
    ),
  );
}

class MainApp extends StatelessWidget {
  const MainApp({super.key});

  @override
  Widget build(BuildContext context) {
    final GoRouter router = GoRouter(
      initialLocation: '/',
      routes: [
        GoRoute(
          path: '/',
          builder: (context, state) => ContactPage(),
        ),
        GoRoute(
          path: '/edit',
          builder: (context, state) => EditPage(),
        ),
        GoRoute(
          path: '/details',
          builder: (context, state) {
            final index = state.extra as int;
            final contact = context.watch<ContactProvider>().contacts[index];
            return DetailsPage(contact: contact);
          },
        ),
      ],
    );

    return MaterialApp.router(
      title: 'Contact List Application',
      routerConfig: router,
      theme: ThemeData(
        colorScheme:ColorScheme.fromSeed(seedColor: Colors.deepPurple,
        brightness: Brightness.dark,),
      ),
    );
  }
}